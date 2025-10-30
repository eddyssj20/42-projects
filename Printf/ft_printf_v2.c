/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:50:41 by elorente          #+#    #+#             */
/*   Updated: 2024/10/28 11:50:41 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long nb, char *base)
{
	int	counter;

	counter = 0;
	if (nb >= 16)
	{
		counter += ft_putnbr_hex(nb / 16, base);
		counter += ft_putchar(base[nb % 16]);
	}
	else
		counter += ft_putchar(base[nb]);
	return (counter);
}

int	ft_putptr(unsigned long nb)
{
	int		counter;

	if (nb == 0)
		return (ft_putstr("(nil)"));
	counter = ft_putstr("0x");
	counter += ft_putnbr_hex(nb, "0123456789abcdef");
	return (counter);
}
