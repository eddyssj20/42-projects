/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:27:59 by elorente          #+#    #+#             */
/*   Updated: 2025/03/02 12:27:59 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int n)
{
	char c;
	if (n > 0)
	{
		ft_putnbr (n / 10);
	}
	c = (n % 10) + '0';
	write (1, &c, 1);
}

int main (int argc, char *argv[])
{
	(void)argv;
	ft_putnbr(argc - 1);
	write (1, "\n", 1);
	return (0);
}