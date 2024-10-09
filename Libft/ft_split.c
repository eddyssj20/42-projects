/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:19:33 by elorente          #+#    #+#             */
/*   Updated: 2024/10/09 11:42:40 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	separa(char str, char c)
{
	if (str == c)
		return (1);
	return (0);
}

int	palabras(char *str, char c)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (str[i])
	{
		if (!separa(str[i], c) && (separa(str[i + 1], c) || str[i + 1] == '\0'))
			p++;
		i++;
	}
	return (p);
}

int	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

int	escribe(char **r, char *str, char c)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (str[i])
	{
		if (!separa(str[i], c))
			i++;
		else
		{
			j = 0;
			while (!separa(str[i + j], c) && (str[i + j]))
				j++;
			r[p] = ft_substr(str, i, j);
			if (r[p] == NULL)
				return (free_str(r));
			i += j;
			p++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		p;
	char	**res;

	if (!s)
		return (NULL);
	p = palabras((char *)s, c);
	res = ft_calloc(p + 1, sizeof(char *));
	if (!res)
		return (NULL);
	if (!escribe(res, (char *)s, c))
		return (NULL);
	return (res);
}
