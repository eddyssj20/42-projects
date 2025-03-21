/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:37:25 by elorente          #+#    #+#             */
/*   Updated: 2025/02/20 18:57:33 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int main (void)
{
	char	c = 'Z';
	char	*str = "Pokemon";
	int		nb = -885685;
	int		unb = 2222334;
	char	*base = "0123456789ABCDEF";
	int		n = 2;

	
	printf("%d\n",ft_putchar(c));
	printf("%d\n",ft_putstr(str));
	printf("%d\n",ft_putnbr(nb));
	printf("%d\n",ft_putnbr_unsigned(unb));
	printf("%d\n",ft_putnbr_hex(unb, base));
	printf("%d\n", ft_isalnum(n));
	printf("%d\n", ft_isalpha(c));
	printf("%d\n", ft_isascii(c));
	printf("%d\n", ft_isdigit(n));
	
	return (0);
}