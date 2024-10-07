/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:38:08 by elorente          #+#    #+#             */
/*   Updated: 2024/09/23 13:11:10 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

/*
int main (void)
{
	const char *a = "Yo soy el super saiyajin Goku";
	int b = 'z';

	char	*r = ft_strchr(a, b);
	if (r != NULL)
		printf("Si hay %s\n", r);
	else
		printf ("No hay %c\n", b);
	return (0);
}
*/