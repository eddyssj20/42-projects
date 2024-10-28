/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:17:20 by elorente          #+#    #+#             */
/*   Updated: 2024/09/23 13:31:28 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdio.h>
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)last);
}

/*
int	main(void)
{
	const char *str = "Yo soy el super saiyajin Goku";
	int ch = 'x';
	char *r = ft_strrchr(str, ch);

	if(r != NULL)
		printf("Lo ultimo es %s\n", r);
	else
		printf("Aqui no hay nadaaaa");
	return (0);
}
*/