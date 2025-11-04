/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:10:33 by elorente          #+#    #+#             */
/*   Updated: 2025/11/04 10:10:33 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFER
# define BUFFER 42
#endif

void	replace(char *str, char *value)
{
	int	i = 0;
	int	j = 0;
	int	len = strlen(value);
	int	printer = 0;
	while (str[i])
	{
		j = 0;
		printer = 0;
		while(j < len && str[i + j] && str[i + j] == value[j])
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

int main(int argc, char *argv[])
{
	if (argc != 2 || argv[1][0] == '\0')
	{
		printf("Error\n");
		return (1);
	}

	char	temp[BUFFER];
	char	*buff;
	char	*res = NULL;
	int		leido = 0;
	int		b_leido = 0;
	int		i = 0;

	while ((b_leido = read(0, temp, BUFFER)) > 0)
	{
		buff = realloc(res, (size_t)leido + (size_t)b_leido + 1);
		if (!buff)
		{
			printf("Error\n");
			free(res);
			return (1);
		}

		res = buff;
		i = 0;

		while (i < b_leido)
		{
			res[leido + i] = temp[i];
			i++;
		}
		leido += b_leido;
		res[leido] = '\0';
	}
	if (b_leido < 0)
	{
		printf("Error\n");
		free(res);
		return (1);
	}
	if (!res)
		return (0);
	
	replace(res, argv[1]);
	free(res);
	return (0);
}