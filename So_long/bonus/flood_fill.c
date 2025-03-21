/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:34:11 by elorente          #+#    #+#             */
/*   Updated: 2025/03/17 17:25:50 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, t_game *game, int y, int x)
{
	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
		return ;
	if (tab[y][x] == '1' || tab[y][x] == 'F')
		return ;
	tab[y][x] = 'F';
	fill(tab, game, y + 1, x);
	fill(tab, game, y - 1, x);
	fill(tab, game, y, x + 1);
	fill(tab, game, y, x - 1);
}

char	**copy_map(char **tab, t_game *game)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc((game->height + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (i < game->height)
	{
		copy[i] = ft_strdup(tab[i]);
		if (!copy[i])
			return (NULL);
		i++;
	}
	return (copy);
}

int	check_element(char **tab, char **copy, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if ((tab[i][j] == 'E' || tab[i][j] == 'C') && copy[i][j] != 'F')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_path(char **tab, t_game *game)
{
	char	**copy;

	copy = copy_map(tab, game);
	if (!copy)
		return (0);
	fill(copy, game, game->p_y, game->p_x);
	if (!check_element(tab, copy, game))
	{
		ft_printf("No hay camino valido\n");
		free(copy);
		close_game(game);
		return (0);
	}
	free_copy(copy, game->height);
	return (1);
}

void	free_copy(char **copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (copy[i])
			free(copy[i]);
		i++;
	}
	free(copy);
}
