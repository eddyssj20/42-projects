/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:24:07 by elorente          #+#    #+#             */
/*   Updated: 2025/03/31 14:03:25 by elorente         ###   ########.fr       */
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
	sprite_check(game);
}

void	draw_sprites(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_father,
			game->window, game->wall, x * 64, y * 64);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_father,
			game->window, game->p1, x * 64, y * 64);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_father,
			game->window, game->coin, x * 64, y * 64);
	else if (game->map[y][x] == 'E' && game->e_true == 1)
		mlx_put_image_to_window(game->mlx_father,
			game->window, game->exit, x * 64, y * 64);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_father,
			game->window, game->floor, x * 64, y * 64);
	else
	{
		ft_printf("Error\n Mapa no valido\n");
		close_game(game);
	}
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
}

void	sprite_check(t_game *game)
{
	if (!game->wall)
	{
		ft_printf("Error\nNo hay Wall sprite\n");
		close_game(game);
	}
	if (!game->p1)
	{
		ft_printf("Error\nNo hay goku\n");
		close_game(game);
	}
	if (!game->exit)
	{
		ft_printf("Error\nNo hay shen long\n");
		close_game(game);
	}
	if (!game->coin)
	{
		ft_printf("Error\nNo hay dragon ball\n");
		close_game(game);
	}
	if (!game->floor)
	{
		ft_printf("Error\nNo hay pasto\n");
		close_game(game);
	}
}
