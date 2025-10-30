/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:39:51 by elorente          #+#    #+#             */
/*   Updated: 2025/03/11 17:16:16 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	separator (char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static int	count_words (char *str)
{
	int		counter;
	int		i;
	
	i = 0;
	counter = 0;
	while (str[i])
	{
		while (str[i] && separator(str[i]) == 1)
			i++;
		if (str[i] && separator(str[i]) == 0)
		{
			counter++;
			while(str[i] && separator(str[i]) == 0)
				i++;
		}
	}
	return (counter);
}

static char *word_dup(const char *s, int len)
{
	char	*buff;
	int		i;
	
	i = 0;
	buff = malloc(sizeof(char) * (len +1));
	if (!buff)
		return (NULL);
	while (i < len)
	{
		buff[i] = s[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

char	**ft_split(char *str)
{
	char	**words;
	int 	n_words;
	int		i;

	n_words = count_words(str);
	i = 0;

	words = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!words)
		return (NULL);
	while (str[i])
	{
		while (str[i] && separator(str[i]) == 1)
			i++;
		if (str[i] && separator(str[i]) == 0)
		{
			char	*start = str;
			int		j;
			j = 0;
			while (str[i] && separator(str[i]) == 0)
			{
				j++;
				str++;
			}
			words[i] = word_dup(start, j);
			i++;
		}
	}
	words[i] = '\0';
	return (words);
}