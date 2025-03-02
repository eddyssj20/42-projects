/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:02:17 by elorente          #+#    #+#             */
/*   Updated: 2025/03/01 17:02:17 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_len (int n)
{
	int i;
	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char *ft_itoa(int nbr)
{
	int len;
	int	size;
	char	*res;

	len = ft_len(nbr);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		res[--len] = (nbr % 10) + '0';
		nbr /= 10;
		len++;
	}
	return (res);
}