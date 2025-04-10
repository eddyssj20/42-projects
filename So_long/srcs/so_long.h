/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:55:55 by elorente          #+#    #+#             */
/*   Updated: 2025/03/29 16:10:44 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../include/mlx.h"
# include "../Libft/libft.h"

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

//Keys//

# define K_ESC 65307
# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100

typedef struct s_game
{
	int			f_x;
	int			f_y;
	int			p_x;
	int			p_y;
	int			e_x;
	int			e_y;
	int			e_true;
	int			mcount;
	int			total_coins;
	int			c_counter;
	void		*mlx_father;
	void		*window;
	char		**map;
	int			width;
	int			height;
	void		*wall;
	void		*floor;
	void		*p1;
	void		*coin;
	void		*exit;
	int			p_counter;
	int			e_counter;
}	t_game;

char	**fill_map(char *ber, char **maparr, t_game *game);
char	**copy_map(char **tab, t_game *game);
int		check_element(char **tab, char **copy, t_game *game);
int		check_path(char **tab, t_game *game);

int		key_press(int key, t_game *game);
int		map_pos(t_game *game);
int		map_size(char *ber);
void	map_wall(t_game *game);
void	valid_map(t_game *game);
void	free_for_all(t_game *game);
void	free_copy(char **copy, int height);
void	process_map(char *line, t_game *game, int i);
char	**allocate_map(t_game *game, char **maparr, char *line, int i);
void	get_map_size(t_game *game, char *ber, int *width, int *height);

void	fill(char **tab, t_game *game, int y, int x);
void	is_rectangular(t_game *game);
void	check_ext(t_game *game, char *map);
void	control_exit(t_game *game);
void	draw_map(t_game *game);
void	free_map(t_game *game);
void	init_all(t_game *game);
void	init_game(t_game *game, char *map_file);
void	load_images(t_game *game);
void	map_ok(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	read_map(char *ber, t_game *game);
void	draw_sprites(t_game *game, int x, int y);
int		close_game(t_game *game);
void	sprite_check(t_game *game);

#endif