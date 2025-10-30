/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:31:05 by elorente          #+#    #+#             */
/*   Updated: 2024/09/24 13:44:07 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char str[] = "Yeah perdonen Kamehameha";
	char x = 'p';
	char *y;

	y = (char *)ft_memchr(str, x, 10);
	
	if (y != NULL)
		printf("Aqui ta '%c' %ld\n", x, y - str);
	else
		printf("Aqui no ta");
	return (0);
}
*/