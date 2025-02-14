/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:46:58 by elorente          #+#    #+#             */
/*   Updated: 2024/09/19 14:24:37 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isascii(int i)
{
	if (i >= 0 && i <= 127)
		return (1);
	return (0);
}

/*
int	main (void)
{
	int	x = 's';
	int y = 'A';
	int	z = '9';
	
	printf("%d",ft_isascii(x));
	printf("%d",ft_isascii(y));
	printf("%d",ft_isascii(z));

	return (0);
}
*/