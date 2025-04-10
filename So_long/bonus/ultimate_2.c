/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:59:23 by elorente          #+#    #+#             */
/*   Updated: 2025/03/25 17:15:59 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_frames(t_game *game)
{
	int	w;
	int	h;

	w = game->width;
	h = game->height;
	game->frames[0] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_1.xpm", &w, &h);
	game->frames[1] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_2.xpm", &w, &h);
	game->frames[2] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_3.xpm", &w, &h);
	game->frames[3] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_4.xpm", &w, &h);
	game->frames[4] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_5.xpm", &w, &h);
	game->frames[5] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_6.xpm", &w, &h);
	game->frames[6] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_7.xpm", &w, &h);
	game->frames[7] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_75.xpm", &w, &h);
	game->frames[8] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_8.xpm", &w, &h);
	load_frames2(game, w, h);
}

void	load_frames2(t_game *game, int w, int h)
{
	game->frames[9] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_9.xpm", &w, &h);
	game->frames[10] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_10.xpm", &w, &h);
	game->frames[11] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_11.xpm", &w, &h);
	game->frames[12] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_12.xpm", &w, &h);
	game->frames[13] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_13.xpm", &w, &h);
	game->frames[14] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_14.xpm", &w, &h);
	game->frames[15] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_15.xpm", &w, &h);
	game->frames[16] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_16.xpm", &w, &h);
	game->frames[17] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_17.xpm", &w, &h);
	game->frames[18] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_18.xpm", &w, &h);
	game->frames[19] = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/re_largo_19.xpm", &w, &h);
	sprite_check(game);
	frame_check(game);
}

void	handle_cinema_key(int key, t_game *game)
{
	if (key == K_ENTER)
	{
		if (game->cinema_step < 7 || game->cinema_step >= 18)
			game->cinema_step++;
		else if (game->cinema_step == 7)
			game->cinema_step = 10;
		else if (game->cinema_step == 10)
			game->cinema_step = 12;
		display_frames(game);
	}
}

void	loop_control(t_game *game, int *loop, int min, int max)
{
	mlx_put_image_to_window(game->mlx_father, game->window,
		game->frames[*loop], 0, 0);
	(*loop)++;
	if (*loop > max)
		*loop = min;
	usleep(100000);
}

void	cinematic_frame(t_game *game, int sleep)
{
	mlx_put_image_to_window(game->mlx_father, game->window,
		game->frames[game->cinema_step], 0, 0);
	usleep(sleep);
}
