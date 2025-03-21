/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_v1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:23:51 by elorente          #+#    #+#             */
/*   Updated: 2024/11/02 17:47:56 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

int	ft_putnbr(int nb)
{
	unsigned int	num;
	int				counter;

	num = nb;
	counter = 0;
	if (nb < 0)
	{
		num = -nb;
		counter += ft_putchar('-');
	}
	if (num > 9)
		counter += ft_putnbr(num / 10);
	counter += ft_putchar((num % 10) + '0');
	return (counter);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int				counter;

	counter = 0;
	if (nb > 9)
		counter += ft_putnbr_unsigned(nb / 10);
	counter += ft_putchar((nb % 10) + '0');
	return (counter);
}
