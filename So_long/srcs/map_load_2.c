/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:22:03 by elorente          #+#    #+#             */
/*   Updated: 2025/03/17 17:46:53 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
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

void	get_map_size(char *ber, int *width, int *height)
{
	int		fd;
	char	*temp;

	*width = 0;
	*height = 0;
	fd = open(ber, O_RDONLY);
	if (fd < 0)
	{
		perror ("Error reading map 1");
		exit (1);
	}
	temp = get_next_line(fd);
	while (temp)
	{
		if (!(*width))
			*width = ft_strlen(temp) - 1;
		(*height)++;
		free (temp);
		temp = get_next_line(fd);
	}
	close(fd);
}
