/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:54:06 by elorente          #+#    #+#             */
/*   Updated: 2025/02/14 20:09:07 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void read_map(char *ber, t_game *game)
{
    char    *temp;
    int     i;
    int     j;
    int     fd;
    
    i = 0;
    j = 0;
    fd = open(ber, O_RDONLY);
    if (fd < 0)
    {
        perror("Error reading map");
        exit(1);
    }
    else
    {
        temp = get_next_line(fd);
        while (temp)
        {
            if (!i)
                i = ft_strlen(temp);
            j++;
            free(temp);
            temp = get_next_line(fd);           
        }
    }
    game->width = i - 1;
    game->height = j;
    close(fd);
}

char **fill_map(char *ber, char **maparr, t_game *game)
{
    int     i;
    int     fd;
    char    *line;
    
    i = 0;
    line = NULL;
    fd = open(ber, O_RDONLY);
    if (fd < 0)
    {
        perror("Error fill map 1");
        exit(1);
    }
    else
    {
        while (i < game->height)
        {
            line = get_next_line(fd);
            if(!line)
                break;
            maparr[i] = ft_strdup(line);
            free(line);
            i++;
        }
    }
    close(fd);
    return (maparr);
}

void draw_map(t_game  *game)
{
    int x;
    int y;

    x = 0;
    while (x < game->width)
    {
        y = 0;
        while (y < game->height)
        {
            draw_sprites(game, x, y);
            y++;
        }
        x++;
    }
}

void free_map(t_game *game)
{
    int i;

    i = 0;
    if (game->map)
    {
        while (game->map[i])
        {
            free(game->map[i]);
            i++;
        }
        free(game->map);
    }
}
