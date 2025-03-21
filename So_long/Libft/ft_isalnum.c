/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:26:41 by elorente          #+#    #+#             */
/*   Updated: 2024/09/19 13:44:09 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isalnum(int i)
{
	if ((i >= 'A' && i <= 'Z')
		|| (i >= 'a' && i <= 'z')
		|| (i >= '0' && i <= '9'))
		return (1);
	return (0);
}

/*
int	main (void)
{
	int	x = 's';
	int y = 'A';
	int	z = '9';
	
	printf("%d",ft_isalnum(x));
	printf("%d",ft_isalnum(y));
	printf("%d",ft_isalnum(z));

	return (0);
}
*/