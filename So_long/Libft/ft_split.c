/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:19:33 by elorente          #+#    #+#             */
/*   Updated: 2024/10/10 14:11:35 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static void	freeall(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static int	nword(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			n++;
		i++;
	}
	return (n);
}

static char	*getword(const char *s, char c)
{
	char	*buffer;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	buffer = malloc(sizeof(char) * (i + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		buffer[i] = s[i];
		i++;
	}
	buffer [i] = '\0';
	return (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char *) * (nword(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i] && j < nword(s, c))
	{
		if (s[i] != c)
		{
			str[j] = getword(s + i, c);
			if (!str[j])
				return (freeall(str), NULL);
			i = i + ft_strlen(str[j]);
			j++;
		}
		else
			i++;
	}
	str[j] = NULL;
	return (str);
}

/*
int main (void)
{
	char	*s = "Comprendez Mendez";
	char	c = ' ';
	char	**str;
	int		i = 0;

	str = ft_split(s, c);
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	freeall(str);
	return(0);
}
*/
