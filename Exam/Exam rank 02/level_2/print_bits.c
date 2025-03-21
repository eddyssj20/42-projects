/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:49:47 by elorente          #+#    #+#             */
/*   Updated: 2025/02/27 19:49:47 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_bits (unsigned char octet)
{
	int		i = 7;
	char	bit;

	while (i >= 0)
	{
		bit = ((octet >> i) & 1) + '0'
		write(1, &bit, 1);
		i--;
	}
}