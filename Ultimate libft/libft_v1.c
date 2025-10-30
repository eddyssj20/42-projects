/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_v1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:33:52 by elorente          #+#    #+#             */
/*   Updated: 2025/02/15 16:37:29 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	n;

	i = 0;
	s = 1;
	n = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	max;

	max = nmemb * size;
	ptr = malloc(max);
	if (ptr == NULL)
		return (NULL);
	ft_bzero (ptr, max);
	return (ptr);
}

int	ft_isalnum(int i)
{
	if ((i >= 'A' && i <= 'Z')
		|| (i >= 'a' && i <= 'z')
		|| (i >= '0' && i <= '9'))
		return (1);
	return (0);
}

int	ft_isalpha(int x)
{
	if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z'))
		return (1);
	return (0);
}
