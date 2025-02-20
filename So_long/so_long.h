/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:55:55 by elorente          #+#    #+#             */
/*   Updated: 2025/02/20 18:28:01 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define  SO_LONG_H


#include "./include/mlx.h"
#include "./include/get_next_line.h"
#include "./include/libft.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

//Keys//

# define K_esc 65307
# define K_w 119
# define K_a 97
# define K_s 115
# define K_d 100

typedef struct s_game
{
    int         p_x;
    int         p_y;
	int			e_x;
	int			e_y;
	int			e_true;
	int			mcount;
	int			total_coins;
	int			c_counter;
    void        *mlx_father;
    void        *window;
    char        **map;
    int         width;
    int         height;
    void        *wall;
    void        *floor;
    void        *P1;
    void        *coin;
    void        *exit;
	int			p_counter;
	int			e_counter;
}   t_game;

char    **fill_map(char *ber, char **maparr, t_game *game);

int     key_press(int key, t_game *game);
int     map_pos(t_game *game);
int     map_size(char *ber);
void	map_wall(t_game *game);
void	valid_map(t_game *game);

void	is_rectangular(t_game *game);
void 	check_ext(char *map);
void	control_exit(t_game *game);
void    draw_map(t_game  *game);
void    free_map(t_game *game);
void	init_all(t_game *game);
void    init_game(t_game *game, char *map_file);
void    load_images(t_game *game);
void	map_ok(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void    move_up(t_game *game);
void    read_map(char *ber, t_game *game);
void    draw_sprites(t_game *game, int x, int y);
void    close_game(t_game *game);

#endif