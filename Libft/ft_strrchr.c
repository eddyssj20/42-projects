/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:17:20 by elorente          #+#    #+#             */
/*   Updated: 2024/10/09 13:42:23 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdio.h>
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	i = ft_strlen(s);
	ch = (unsigned char)c;
	if (ch == '\0')
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char *str = "Yo soy el super saiyajin Goku";
	int ch = 'G';
	char *r = ft_strrchr(str, ch);

	if(r != NULL)
		printf("Lo ultimo es %s\n", r);
	else
		printf("Aqui no hay nadaaaa");
	return (0);
}
*/
