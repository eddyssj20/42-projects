/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:29:28 by elorente          #+#    #+#             */
/*   Updated: 2024/09/23 10:31:00 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_tolower(int i)
{
	if (i >= 'A' && i <= 'Z')
		return (i + 32);
	return (i);
}
/*
int main(void)
{
	int test1 = 'A';
	int test2 = 'H';

	printf("%c", ft_tolower(test1));
	printf("%c", ft_tolower(test2));

	return 0;
}
*/