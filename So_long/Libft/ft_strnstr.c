/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:46:06 by elorente          #+#    #+#             */
/*   Updated: 2024/09/26 12:35:03 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char *b = "Charmander Charmeleon Charizard";
	const char *l = "Charmeleon";
	size_t len = 40;

	char *r = ft_strnstr(b, l,len);
	if (r != NULL)
		printf("Atrapado'%s'\n", r);
	else
		printf("No atrapado'%s'\n", l);

	return (0);

}
*/