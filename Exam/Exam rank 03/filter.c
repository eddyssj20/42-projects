/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:00:27 by elorente          #+#    #+#             */
/*   Updated: 2025/09/25 20:53:35 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#ifndef BUFFER
# define BUFFER 10000
#endif

void	replace(char *str, char *value)
{
	int	i = 0;
	int	j;
	int	len = 0;
	int	printer = 0;

	len = strlen(value);
	while (str[i])
	{
		j = 0;
		printer = 0;
		while (j < len && str[i + j] && str[i + j] == value[j])
			j++;
		if (j == len)
		{
			while (printer != len)
			{
				printf("*");
				printer++;
			}
			i += len;
		}
		else
		{
			printf("%c", str[i]);
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error: No hay suficientes argumentos\n");
		return (1);
	}
	char	*res;
	char	*value;
	int		j = 0;
	value = argv[1];
	res = malloc(1000);
	while ((j = read(0, res, 1000)) > 0)
	{
		res[j] = '\0';
		replace(res, value);
	}
	free (res);
	return (0);
}
