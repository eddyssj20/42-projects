/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:55:55 by elorente          #+#    #+#             */
/*   Updated: 2025/03/21 18:04:08 by elorente         ###   ########.fr       */
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
# define K_ENTER 65293

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
	void		*frieza;
	void		*p1;
	void		*coin;
	void		*exit;
	int			p_counter;
	int			e_counter;
	int			cinema_active;
	int			cinema_step;
	void		*frames[20];
	int			enemy_x;
	int			enemy_y;
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
char	**allocate_map(char **maparr, char *line, int i, int fd);
void	get_map_size(char *ber, int *width, int *height);

void	fill(char **tab, t_game *game, int y, int x);
void	is_rectangular(t_game *game);
void	check_ext(char *map);
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

//Bonus//

void	display_moves(t_game *game);
void	collector(t_game *game, char newsprite);
void	trigger_cinema(t_game *game, int enemy_x, int enemy_y);
void	display_frames(t_game *game);
void	load_frames(t_game *game);
void	free_frames(t_game *game);
void	load_frames2(t_game *game, int w, int h);
void	handle_cinema_key(int key, t_game *game);
void	loop_control(t_game *game, int *loop, int min, int max);
void	cinematic_frame(t_game *game, int sleep);
void	cinematic_step(t_game *game, int sleep);
void	display_frames_2(t_game *game);

#endif