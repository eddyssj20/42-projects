/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:54:56 by elorente          #+#    #+#             */
/*   Updated: 2024/10/09 13:10:13 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(int nbr)
{
	int	c;

	c = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		c++;
	}
	return (c);
}

void	calc(unsigned int nbr, int len, int fd)
{
	unsigned int	d;

	d = 1;
	while (--len)
		d *= 10;
	nbr = (nbr / d) % 10;
	nbr += '0';
	write(fd, &nbr, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	num;
	int				size;

	if (nb < 0)
	{
		num = -nb;
		write(fd, "-", 1);
	}
	else
		num = nb;
	if (num == 0)
		write(fd, "0", 1);
	size = count(num);
	while (size --)
		calc(num, size, fd);
}
