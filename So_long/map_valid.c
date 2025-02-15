/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:46:23 by elorente          #+#    #+#             */
/*   Updated: 2025/02/15 17:54:16 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_pos(t_game *game)
{
    int i;
    int j;
    
    i = 0;
    while (i < game->height -1)
    {
        j = 0;
        while (game->map[i][j] != '\n')
        {
            if (game->map[i][j] == 'P')
            {
                game->player.p_x = j;
                game->player.p_y = i;
            }
            j++;
        }
        i++;
    }
    return (1);
}