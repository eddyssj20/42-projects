/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:00:44 by elorente          #+#    #+#             */
/*   Updated: 2025/02/15 19:36:30 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_press(int key, t_game *game)
{
    if (key == K_esc)
        close_game(game);
    else if (key == K_w)
        move_up(game);
    return (0);
}

void move_up(t_game *game)
{
    int     old_y;
    int     newsprite;

    old_y = game->player.p_y;
    newsprite = game->map[old_y -1][game->player.p_x];
    if (newsprite != '1')
    {
        mlx_put_image_to_window(game->mlx_father, game->window, game->floor, game->player.p_x * 64, old_y * 64);
        game->map[old_y][game->player.p_x] = '0';
        game->player.p_y--;
        mlx_put_image_to_window(game->mlx_father, game->window, game->P1, game->player.p_x * 64, game->player.p_y * 64);
        game->map[game->player.p_y][game->player.p_x] = 'P';
    }
}