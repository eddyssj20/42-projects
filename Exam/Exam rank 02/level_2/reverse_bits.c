/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:56:48 by elorente          #+#    #+#             */
/*   Updated: 2025/02/27 19:56:48 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char reverse_bits(unsigned char octet)
{
	unsigned char	bit;
	int				i;

	bit = 0;
	i = 0;
	while (i <= 7)
	{
		bit = (bit << 1) | (octet & 1);
		octet >>= 1;
		i++;
	}
	return (bit);
}