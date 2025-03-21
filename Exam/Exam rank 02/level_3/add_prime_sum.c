/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:59:08 by elorente          #+#    #+#             */
/*   Updated: 2025/02/27 22:59:08 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
	int i = 0;
	int	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 +(str[i] - '0');
		i++;
	}
	return (num);
}

int is_prime(int n)
{
	int	i = 2;
	if (n < 2)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void ft_putnbr(int n)
{
	char c;
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void ft_aps(char *s)
{
	int	num;
	int	sum = 0;
	int	i = 2;
	
	num = ft_atoi(s);
	if (num <= 0)
	{
		write (1, "0\n", 2);
		return;
	}
	while (i <= num)
	{
		if (is_prime(i))
			sum += i;
		i++;
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
}

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		write (1, "0\n", 2);
		return (0);
	}
	ft_aps(argv[1]);
	return(0);
}