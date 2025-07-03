/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:51:40 by elorente          #+#    #+#             */
/*   Updated: 2025/06/27 19:27:16 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
	char	c;
	int		i = 0;
	int		leido = 0;

	if (fd < 0)
		return NULL;

	char	*res = malloc(BUFFER_SIZE);
	
	while ((leido  = read(fd, &c, 1)) > 0)
	{
		res[i] = c;
		i++;
		if (c == '\n')
			break;
	}
	if (i == 0 || leido < 0)
	{
		free(res);
		return (NULL);
	}
	res[i] = '\0';
	return (res);
}

int main (int arcg, char *argv[])
{
	int		fd = 0;
	char	*line;

	if (arcg > 1)
		fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("line = %s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}