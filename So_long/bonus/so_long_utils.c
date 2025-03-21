/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:24:07 by elorente          #+#    #+#             */
/*   Updated: 2025/03/18 12:01:35 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	img_x;
	int	img_y;

	game->wall = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/Wall.xpm", &img_x, &img_y);
	game->p1 = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/P1.xpm", &img_x, &img_y);
	game->floor = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/Grass.xpm", &img_x, &img_y);
	game->coin = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/Coin.xpm", &img_x, &img_y);
	game->exit = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/Exit.xpm", &img_x, &img_y);
	game->frieza = mlx_xpm_file_to_image(game->mlx_father,
			"Ast/Frieza.xpm", &img_x, &img_y);
	load_frames(game);
}

void	draw_sprites(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_father,
		game->window, game->floor, x * 64, y * 64);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_father,
			game->window, game->wall, x * 64, y * 64);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_father,
			game->window, game->p1, x * 64, y * 64);
	else if (game->map[y][x] == 'B')
		mlx_put_image_to_window(game->mlx_father,
			game->window, game->frieza, x * 64, y * 64);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_father,
			game->window, game->coin, x * 64, y * 64);
	else if (game->map[y][x] == 'E' && game->e_true == 1)
		mlx_put_image_to_window(game->mlx_father,
			game->window, game->exit, x * 64, y * 64);
}

void	control_exit(t_game *game)
{
	if (game->total_coins == 0)
	{
		game->map[game->e_y][game->e_x] = 'E';
		game->e_true = 1;
	}
}

void	init_all(t_game *game)
{
	game->mcount = 0;
	game->width = 0;
	game->height = 0;
	game->total_coins = 0;
	game->c_counter = 0;
	game->p_counter = 0;
	game->e_counter = 0;
	game->cinema_active = 0;
}

void	sprite_check(t_game *game)
{
	if (!game->wall)
	{
		ft_printf("No hay Wall sprite");
		exit(1);
	}
	if (!game->p1)
	{
		ft_printf("No hay goku");
		exit(1);
	}
	if (!game->exit)
	{
		ft_printf("No hay shen long");
		exit(1);
	}
	if (!game->coin)
	{
		ft_printf("No hay dragon ball");
		exit(1);
	}
	if (!game->floor)
	{
		ft_printf("toca pasto");
		exit(1);
	}
}
