/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:00:51 by elorente          #+#    #+#             */
/*   Updated: 2024/11/02 17:47:26 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	select_type(va_list parameters, char str)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(parameters, int));
	else if (str == 's')
		count += ft_putstr(va_arg(parameters, char *));
	else if (str == 'p')
		count += ft_putptr(va_arg(parameters, unsigned long));
	else if (str == 'd')
		count += ft_putnbr(va_arg(parameters, int));
	else if (str == 'i')
		count += ft_putnbr(va_arg(parameters, int));
	else if (str == 'u')
		count += ft_putnbr_unsigned(va_arg(parameters, unsigned int));
	else if (str == 'x')
		count += ft_putnbr_hex(va_arg(parameters, unsigned int),
				"0123456789abcdef");
	else if (str == 'X')
		count += ft_putnbr_hex(va_arg(parameters, unsigned int),
				"0123456789ABCDEF");
	else if (str == '%')
		count += ft_putchar(str);
	return (count);
}

int	ft_printf(char const *total_str, ...)
{
	va_list	params;
	int		counter;

	counter = 0;
	va_start(params, total_str);
	while (*total_str)
	{
		if (*total_str == '%')
		{
			total_str++;
			counter += select_type(params, *total_str++);
		}
		else
			counter += ft_putchar(*total_str++);
	}
	va_end(params);
	return (counter);
}

/*
%c char
%s string
%p pointer
%d int
%i int
%u unsigned int
%x hexadecimal min
%X hexadecimal MAYUS
%% percentage
*/
