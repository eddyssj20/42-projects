/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 23:33:24 by elorente          #+#    #+#             */
/*   Updated: 2025/02/24 16:57:14 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int n)
{
	char c;
	if (n >= 10)
		ft_putnbr(n /10);
	c = (n % 10) + '0';
	write (1, &c, 1);
}
void ft_fizzbuzz(void)
{
	int	i;
	i = 1;
	while (i < 101)
	{
		if(i % 3 == 0 && i % 5 == 0)
		{
			write(1, "fizzbuzz", 8);
		}
		else if(i % 3 == 0)
		{
			write (1, "fizz", 4);
		}
		else if(i % 5 == 0)
		{
			write (1, "buzz", 4);
		}
		else
			ft_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
}

int main (void)
{
	ft_fizzbuzz();
	return (0);
}