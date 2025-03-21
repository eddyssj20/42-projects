/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:38:40 by elorente          #+#    #+#             */
/*   Updated: 2024/09/19 13:44:39 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isalpha(int x)
{
	if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z'))
		return (1);
	return (0);
}

/*
int	main (void)
{
	int	x = 's';
	int y = 'A';
	int	z = '9';
	
	printf("%d",ft_isalpha(x));
	printf("%d",ft_isalpha(y));
	printf("%d",ft_isalpha(z));

	return (0);
}
*/