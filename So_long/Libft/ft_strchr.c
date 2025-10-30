/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:38:08 by elorente          #+#    #+#             */
/*   Updated: 2024/10/09 14:13:48 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)c;
	if (ch == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)(i + s));
		i++;
	}
	return (NULL);
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
