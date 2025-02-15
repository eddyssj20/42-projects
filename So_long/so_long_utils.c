/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:24:07 by elorente          #+#    #+#             */
/*   Updated: 2025/02/15 17:02:20 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_images(t_game *game)
{
    int img_x;
    int img_y;
    
    game->wall = mlx_xpm_file_to_image(game->mlx_father, "Ast/Wall.xpm", &img_x, &img_y);
    game->P1 = mlx_xpm_file_to_image(game->mlx_father, "Ast/P1.xpm", &img_x, &img_y);
    game->floor = mlx_xpm_file_to_image(game->mlx_father, "Ast/Grass.xpm", &img_x, &img_y);
    game->coin = mlx_xpm_file_to_image(game->mlx_father, "Ast/Coin.xpm", &img_x, &img_y);
    game->exit = mlx_xpm_file_to_image(game->mlx_father, "Ast/Exit.xpm", &img_x, &img_y);

    if (!game->wall)
    {
        write(2, "Noooo", 5);
        exit(1);
    }
}

void draw_sprites(t_game *game, int x, int y)
{
    mlx_put_image_to_window(game->mlx_father, game->window, game->floor, x * 64, y * 64);
    if (game->map[y][x] == '1')
        mlx_put_image_to_window(game->mlx_father, game->window, game->wall, x * 64, y * 64);
    else if (game->map[y][x] == 'P')
        mlx_put_image_to_window(game->mlx_father, game->window, game->P1, x * 64, y * 64);
    /*else if (game->map[y][x] == '0')
        mlx_put_image_to_window(game->mlx_father, game->window, game->floor, x * 64, y * 64);*/
    else if (game->map[y][x] == 'C')
        mlx_put_image_to_window(game->mlx_father, game->window, game->coin, x * 64, y * 64);
    else if (game->map[y][x] == 'E')
        mlx_put_image_to_window(game->mlx_father, game->window, game->exit, x * 64, y * 64);  
}