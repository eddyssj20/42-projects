/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:46:23 by elorente          #+#    #+#             */
/*   Updated: 2025/02/16 14:34:17 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_pos(t_game *game)
{
    int i;
    int j;
    
	game->total_coins = 0;
	
    i = 0;
	
    while (i < game->height)
    {
        j = 0;
        while (game->map[i][j] && game->map[i][j] != '\n')
        {
            if (game->map[i][j] == 'P')
            {
                game->p_x = j;
                game->p_y = i;
            }
			if (game->map[i][j] == 'C')
				game->total_coins++;
			j++;
			if (game->map[i][j] == 'E')
			{
				game->e_x = j;
				game->e_y = i;
				game->e_true = 0;
			}
        }
        i++;
    }
    return (0);
}