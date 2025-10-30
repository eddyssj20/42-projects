/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:46:23 by elorente          #+#    #+#             */
/*   Updated: 2025/03/31 14:00:08 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map(t_game *game)
{
	map_wall(game);
	is_rectangular(game);
	if (!check_path(game->map, game))
	{
		ft_printf("Error\nMapa no valido\n");
		close_game(game);
	}
	if (game->p_counter != 1)
	{
		ft_printf("Error\nMapa no valido\n");
		close_game(game);
	}
	if (game->e_counter != 1)
	{
		ft_printf("Error\nUsa solo 1 salida %d\n", game->e_counter);
		close_game(game);
	}
	if (game->c_counter <= 0)
	{
		ft_printf("Error\nNo hay suficientes Dragon balls\n");
		close_game(game);
	}
}

void	check_ext(t_game *game, char *map)
{
	char	*name_ext;
	char	*ext;

	ext = ".ber";
	name_ext = ft_substr(map, (ft_strlen(map) - 4), 4);
	if (ft_strncmp(name_ext, ext, ft_strlen(name_ext)) != 0)
	{
		ft_printf("Error\nNo es archivo ber\n");
		free(name_ext);
		close_game(game);
	}
	free (name_ext);
}

int	map_pos(t_game *game)
{
	int	i;
	int	j;

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
				game->p_counter++;
			}
			if (game->map[i][j] == 'C')
			{
				game->total_coins++;
				game->c_counter++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	map_wall(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			ft_printf("Error\nFaltan paredes\n");
			close_game(game);
		}
		i++;
	}
	while (j < game->width)
	{
		if (game->map[0][j] != '1' || game->map[game->height - 1][j] != '1')
		{
			ft_printf("Error\nFaltan paredes\n");
			close_game(game);
		}
		j++;
	}
}

void	is_rectangular(t_game *game)
{
	int		i;
	size_t	w;

	w = ft_strlen(game->map[0]);
	i = 0;
	if (w > 30 || game->height > 30)
	{
		printf("Error\nMapa muy grande\n");
		close_game(game);
	}
	while (i < game->height)
	{
		if (ft_strlen(game->map[i]) != w)
		{
			ft_printf("Error\nMapa no valido\n");
			close_game(game);
		}
		i++;
	}
}
