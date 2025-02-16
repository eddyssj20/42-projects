/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:00:44 by elorente          #+#    #+#             */
/*   Updated: 2025/02/16 14:09:36 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_press(int key, t_game *game)
{
	if (key == K_esc)
        close_game(game);
    else if (key == K_w || key == 65362)
		move_up(game);
	else if (key == K_s || key == 65364)
		move_down(game);
	else if (key == K_d || key == 65363)
		move_right(game);
	else if (key == K_a || key == 65361)
		move_left(game);
    mlx_clear_window(game->mlx_father, game->window);
    draw_map(game);
    return (0);
}

void move_up(t_game *game)
{
	int		old_y;
	char	newsprite;

    old_y = game->p_y;
    if (old_y - 1 < 0)
        return;
    newsprite = game->map[old_y - 1][game->p_x];    
	if (newsprite != '1')
    {
		if (newsprite == 'C')
			game->total_coins--;
		if (newsprite == 'E' && game->total_coins == 0)
		{
			ft_printf("SAL DE AHI SHENLON Y CUMPLE MI DESEO\n");
			close_game(game);
		}
        //Borro antiguo//
		game->map[old_y][game->p_x] = '0';
        //Hago nuevo//
        game->p_y--;
		game->map[game->p_y][game->p_x] = 'P';
		game->mcount++;
		ft_printf("Moves: %d\n", game->mcount);
    }
}

void move_down(t_game *game)
{
    int     old_y;
    char    newsprite;

    old_y = game->p_y;
    if (old_y + 1 < 0)
        return;
    newsprite = game->map[old_y + 1][game->p_x];    
	if (newsprite != '1')
    {
		if (newsprite == 'C')
			game->total_coins--;
		if (newsprite == 'E' && game->total_coins == 0)
		{
			ft_printf("SAL DE AHI SHENLON Y CUMPLE MI DESEO\n");
			close_game(game);
		}
		//Borro antiguo//
		game->map[old_y][game->p_x] = '0';
        //Hago nuevo//
        game->p_y++;
		game->map[game->p_y][game->p_x] = 'P';
		game->mcount++;
		ft_printf("Moves: %d\n", game->mcount);
    }
}

void move_right(t_game *game)
{
    int     old_x;
    char    newsprite;

    old_x = game->p_x;
    if (old_x + 1 < 0)
        return;
    newsprite = game->map[game->p_y][old_x + 1];    
	if (newsprite != '1')
    {
		if (newsprite == 'C')
			game->total_coins--;
		if (newsprite == 'E' && game->total_coins == 0)
		{
			ft_printf("SAL DE AHI SHENLON Y CUMPLE MI DESEO\n");
			close_game(game);
		}
        //Borro antiguo//
		game->map[game->p_y][game->p_x] = '0';
        //Hago nuevo//
        game->p_x++;
		game->map[game->p_y][game->p_x] = 'P';
		game->mcount++;
		ft_printf("Moves: %d\n", game->mcount);
    }
}

void move_left(t_game *game)
{
    int     old_x;
    char    newsprite;

    old_x = game->p_x;
    if (old_x - 1 < 0)
        return;
    newsprite = game->map[game->p_y][old_x - 1];    
	if (newsprite != '1')
    {
		if (newsprite == 'C')
			game->total_coins--;
		if (newsprite == 'E' && game->total_coins == 0)
		{
			ft_printf("SAL DE AHI SHENLON Y CUMPLE MI DESEO\n");
			close_game(game);
		}
        //Borro antiguo//
		game->map[game->p_y][game->p_x] = '0';
        //Hago nuevo//
        game->p_x--;
		game->map[game->p_y][game->p_x] = 'P';
		game->mcount++;
		ft_printf("Moves: %d\n", game->mcount);
    }
}