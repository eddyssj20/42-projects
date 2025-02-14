/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:25:34 by elorente          #+#    #+#             */
/*   Updated: 2024/09/19 14:27:46 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isprint(int i)
{
	if (i >= 32 && i <= 126)
		return (1);
	return (0);
}

/*
int	main (void)
{
	int	x = 's';
	int y = 'A';
	int	z = '9';
	
	printf("%d",ft_isprint(x));
	printf("%d",ft_isprint(y));
	printf("%d",ft_isprint(z));

	return (0);
}
*/