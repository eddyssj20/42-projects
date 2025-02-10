/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:55:55 by elorente          #+#    #+#             */
/*   Updated: 2025/02/10 20:56:17 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define  SO_LONG_H


#include "./include/mlx.h"
#include "./include/get_next_line.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_game
{
    void        *mlx_father;
    void        *window;
    char        **map;
    int         width;
    int         height;
}   t_game;

int key_press(int key, t_game *game);
int     map_size(char *ber);

void    free_map(t_game *game);
void    init_game(t_game *game);
void    read_map(char *ber, t_game *game);
void    draw_map(t_game *game);
void    close_game(t_game *game);

#endif