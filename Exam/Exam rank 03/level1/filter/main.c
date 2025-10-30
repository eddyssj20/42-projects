/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:05:29 by elorente          #+#    #+#             */
/*   Updated: 2025/10/23 17:15:16 by elorente         ###   ########.fr       */
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

int main(int argc, char *argv[])
{
	if (argc != 2 || argv[1][0] == '\0')
	{
		printf("Error argumentos");
		return(1);
	}

	char	temp[BUFFER];
	char	*buff;
	char	*res = NULL;
	int		t_leido = 0;
	int		b_leido = 0;
	int		i;

	while ((b_leido = read(0, temp, BUFFER)) > 0)
	{
		buff = realloc(res, (size_t)t_leido + (size_t)b_leido + 1);
		if (!buff)
		{
			printf("Error Realloc");
			free(res);
			return (1);
		}
		res = buff;
		i = 0;
		while (i < b_leido)
		{
			res[t_leido + i] = temp[i];
			i++;
		}
		t_leido += b_leido;
		res[t_leido] = '\0';
	}
	if (!res)
		return (0);
	if (b_leido < 0)
	{
		printf("Error leyendo");
		free(res);
		return (1);
	}
	replace(res, argv[1]);
	free(res);
	return (0);
}