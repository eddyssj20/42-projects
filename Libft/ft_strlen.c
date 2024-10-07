/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:36:39 by elorente          #+#    #+#             */
/*   Updated: 2024/09/19 14:46:46 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

/*
int	main (void)
{
	char	a[100] = "Alguna vez has sentido el cosmos arder dentro de ti?";
	int	l;

	l = ft_strlen(a);

	printf("%d",l);
	return (0);
}
*/