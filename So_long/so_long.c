/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:08:13 by elorente          #+#    #+#             */
/*   Updated: 2025/02/16 13:48:50 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void close_game(t_game *game)
{
    if (game->wall)
        mlx_destroy_image(game->mlx_father, game->wall);
    free_map(game);
    mlx_destroy_window(game->mlx_father, game->window);
    mlx_destroy_display(game->mlx_father);
    free(game->mlx_father);
    exit(0);
}

void init_game(t_game *game, char *map_file)
{
    game->mlx_father = mlx_init();
    if (!game->mlx_father)
    {
        perror("Error Minilibx");
        exit (1);
    }
    game->window = mlx_new_window(game->mlx_father, 1080, 720, "v0.4");
    if (!game->window)
    {
        perror("Error creando window");
        free(game->mlx_father),
        exit(1);
    }
    game->mcount = 0;
	load_images(game);
    fill_map(map_file, game->map, game);
	map_pos(game);
	control_exit(game);
    draw_map(game);
    mlx_key_hook(game->window, key_press, game);
    mlx_loop(game->mlx_father);
}

int main(int argc, char **argv)
{
    t_game *game;
    
    if(argc != 2)
    {
        write(2, "mapa listo", 10);
        return (1);
    }
    game = ft_calloc(1, sizeof(t_game));
    if (!game)
    {
        write(1, "error calloc", 13);
        return(0);
    }
    read_map(argv[1], &game);
    init_game(&game, argv[1]);

    return (0);
}
