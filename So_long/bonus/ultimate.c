/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:08:54 by elorente          #+#    #+#             */
/*   Updated: 2025/03/21 18:15:21 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(t_game *game)
{
	char	*moves_str;

	moves_str = ft_itoa(game->mcount);
	mlx_string_put(game->mlx_father, game->window, 10, 20, 0x000000, "Moves: ");
	mlx_string_put(game->mlx_father, game->window, 70, 20, 0x000000, moves_str);
	free(moves_str);
}

void	collector(t_game *game, char newsprite)
{
	if (newsprite == 'C')
		game->total_coins--;
	if (newsprite == 'E' && game->total_coins == 0)
	{
		ft_printf("SAL DE AHI SHENLON Y CUMPLE MI DESEO\n");
		close_game(game);
	}
}

void	trigger_cinema(t_game *game, int enemy_x, int enemy_y)
{
	game->cinema_active = 1;
	game->cinema_step = 0;
	game->enemy_x = enemy_x;
	game->enemy_y = enemy_y;
	mlx_clear_window(game->mlx_father, game->window);
	mlx_put_image_to_window(game->mlx_father,
		game->window, game->frames[0], 0, 0);
	mlx_do_sync(game->mlx_father);
}

void	display_frames(t_game *game)
{
	static int	loop = 7;

	if (game->cinema_active == 0)
		return ;
	if (game->cinema_step < 19)
		mlx_clear_window(game->mlx_father, game->window);
	if (game->cinema_step >= 0 && game->cinema_step < 7)
	{
		cinematic_frame(game, 0);
		return ;
	}
	if (game->cinema_step == 7)
	{
		mlx_loop_hook(game->mlx_father, (void *)&display_frames, game);
		loop_control(game, &loop, 7, 9);
		return ;
	}
	display_frames_2(game);
}

void	free_frames(t_game *game)
{
	int	i;

	i = 0;
	while (i <= 19)
	{
		if (game->frames[i] != NULL)
		{
			mlx_destroy_image(game->mlx_father, game->frames[i]);
			game->frames[i] = NULL;
		}
		i++;
	}
}
