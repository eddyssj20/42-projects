/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:54:06 by elorente          #+#    #+#             */
/*   Updated: 2025/03/31 14:02:11 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *ber, t_game *game)
{
	get_map_size(game, ber, &game->width, &game->height);
	game->map = ft_calloc(game->height + 1, sizeof(char *));
	if (!game->map)
	{
		ft_printf("Error\ncalloc\n");
		close_game(game);
	}
	ft_memset(game->map, 0, (game->height + 1) * sizeof(char *));
}

char	**allocate_map(t_game *game, char **maparr, char *line, int i)
{
	maparr[i] = ft_strdup(line);
	if (!maparr[i])
	{
		ft_printf("Error\nfill map\n");
		close_game(game);
	}
	return (maparr);
}

void	process_map(char *line, t_game *game, int i)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == 'E')
		{
			game->e_x = j;
			game->e_y = i;
			game->e_true = 0;
			game->e_counter++;
			line[j] = '0';
		}
		j++;
	}
}

char	**fill_map(char *ber, char **maparr, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(ber, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nFill map 2\n");
		close_game(game);
	}
	while (i < game->height)
	{
		line = get_next_line(fd);
		maparr = allocate_map(game, maparr, line, i);
		process_map(maparr[i], game, i);
		free(line);
		i++;
	}
	maparr[i] = NULL;
	close(fd);
	return (maparr);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

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
