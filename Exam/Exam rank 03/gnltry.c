/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnltry.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:14:56 by elorente          #+#    #+#             */
/*   Updated: 2025/09/25 17:19:45 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*gnl(int fd)
{
	char	c;
	int		i = 0;
	int		leido = 0;

	if (fd < 0)
		return NULL;

	char	*res = malloc(BUFFER_SIZE);
	while((leido = read(fd, &c, 1)) > 0)
	{
		res[i] = c;
		i++;
		if (c == '\n')
			break;
	}
	if (i == 0 || leido < 0)
	{
		free(res);
		return NULL;
	}
	res[i] = '\0';
	return (res);
}