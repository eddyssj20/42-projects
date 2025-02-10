/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:08:13 by elorente          #+#    #+#             */
/*   Updated: 2025/02/10 21:08:35 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_size(char *ber)
{
    int     fd;
    int     height;
    char    *line;
    
    fd = open(ber, O_RDONLY);
    height = 0;
    if (fd < 0)
    {
        write(2, "Error", 5);
        exit(1);
    }
    while ((line = get_next_line(fd)))
    {
        free(line);
        height++;
    }
    close(fd);
    return (height);
}

void read_map(char *ber, t_game *game)
{
    int fd;
    int i;

    fd = open(ber, O_RDONLY);
    i = 0;
    
    if (fd < 0)
    {
        write(2, "Error", 5);
        exit(1);
    }
    
    game->height = map_size(ber);
    game->map = malloc(sizeof(char *) * (game->height +1));
    
    while ((game->map[i] = get_next_line(fd)))
        i++;
    game->map[i] = NULL;
    
    close(fd);
}

void close_game(t_game *game)
{
    free_map(game);
    mlx_destroy_window(game->mlx_father, game->window);
    exit(0);
}

int key_press(int key, t_game *game)
{
    if (key == 65307)
        close_game(game);
    return (0);
}

void init_game(t_game *game)
{
    game->mlx_father = mlx_init();
    game->window = mlx_new_window(game->mlx_father, 3840, 2160, "v0.2");
    
    mlx_key_hook(game->window, key_press, game);
    mlx_loop(game->mlx_father);
}

int main(int argc, char **argv)
{
    t_game game;
    
    if(argc != 2)
    {
        write(2, "mapa listo", 10);
        return (1);
    }
    
    read_map(argv[1], &game);
    init_game(&game);

    return (0);
}