/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:47:40 by elorente          #+#    #+#             */
/*   Updated: 2024/10/29 18:47:40 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	select_type(va_list parameters, char complete_str);
int	ft_printf(char const *total_str, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_putnbr_hex(unsigned long nb, char *base);
int	ft_putptr(unsigned long nb);

#endif