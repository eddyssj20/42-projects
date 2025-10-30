/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:30:10 by elorente          #+#    #+#             */
/*   Updated: 2025/10/30 16:47:53 by elorente         ###   ########.fr       */
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
	int		i = 0;
	int		j;
	int		len = 0;
	int		printer = 0;

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

int main (int argc, char *argv[])
{
	if (argc != 2 || argv[1][0] == '\0')
	{
		printf("Error\n");
		return (1);
	}

	char	temp[BUFFER];
	char	*res = NULL;
	char	*buff;
	int		leido = 0;
	int		b_leido;
	int		i;
	
	while ((b_leido = read(0, temp, BUFFER)) > 0)
	{
		buff = realloc(res, (size_t)leido + (size_t)b_leido + 1);
		if (!buff)
		{
			printf("Error realloc\n");
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
		printf("Error leyendo");
		free(res);
		return (1);
	}
	if (!res)
		return (0);
	replace(res, argv[1]);
	free(res);
	return(0);
}