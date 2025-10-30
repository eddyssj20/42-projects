/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:05:49 by elorente          #+#    #+#             */
/*   Updated: 2024/09/18 14:26:17 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isdigit(int x)
{
	if ((x >= '0' && x <= '9'))
		return (1);
	return (0);
}

/*
int	main (void)
{
	int	x = 's';
	int y = 'A';
	int	z = '9';
	
	printf("%d",ft_isdigit(x));
	printf("%d",ft_isdigit(y));
	printf("%d",ft_isdigit(z));

	return (0);
}
*/