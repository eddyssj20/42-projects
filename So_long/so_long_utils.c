/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:24:07 by elorente          #+#    #+#             */
/*   Updated: 2025/02/10 20:52:19 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(t_game *game)
{
    int i;

    i = 0;
    if (game->map)
    {
        while (game->map)
        {
            free(game->map);
            i++;
        }
        free(game->map);
    }
}