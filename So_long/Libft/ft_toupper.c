/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:25:48 by elorente          #+#    #+#             */
/*   Updated: 2024/09/23 10:28:04 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_toupper(int x)
{
	if (x >= 'a' && x <= 'z')
		return (x - 32);
	return (x);
}

/*
int	main (void)
{
	int	t1 = 'z';
	int t2 = 'd';

	printf ("%c", ft_toupper(t1));
	printf ("%c", ft_toupper(t2));

	return (0);
}
*/