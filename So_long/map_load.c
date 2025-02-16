/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:54:06 by elorente          #+#    #+#             */
/*   Updated: 2025/02/16 14:09:13 by elorente         ###   ########.fr       */
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
    game->map = ft_calloc(j + 1, sizeof(char *));
    if (!game->map)
    {
        write(1, "Error Calloc read", 18);
        close(fd);
        exit (1);
    }
    ft_memset (game->map, 0, (j + 1) * sizeof(char *));
    close(fd);
}

char **fill_map(char *ber, char **maparr, t_game *game)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

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
            if (!maparr[i])
            {
                write(1, "Error fill map 2", 17);
                close (fd);
                exit (1);
            }
			j = 0;
			while (maparr[i][j])
			{
				if (maparr[i][j] == 'E' && game->e_true == 0)
					maparr[i][j] = '0';
				j++;
			}
			
            free(line);
            i++;
        }
    }
    maparr[i] = NULL;
    close(fd);
    return (maparr);
}

void draw_map(t_game  *game)
{
    int x;
    int y;

	control_exit(game);
    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            draw_sprites(game, x, y);
            x++;
        }
        y++;
    }
}

void free_map(t_game *game)
{
	int	i;

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
