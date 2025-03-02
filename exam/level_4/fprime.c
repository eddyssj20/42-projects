/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:34:15 by elorente          #+#    #+#             */
/*   Updated: 2025/03/01 16:34:15 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void ft_prime(int n)
{
	int	prime;

	prime = 2;

	if (n == 1)
	{
		printf("1");
		return;
	}
	while (prime <= n)
	{
		if ((n % prime) == 0)
		{
			printf("%d", prime);
			if (n != prime)
				printf("*");
			n /= prime;
		}
		else
			prime++;
	}
	printf("\n");

}

int main (int argc, char *argv[])
{
	int	n = 0;
	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	n = atoi(argv[1]);
	if (n <= 0)
	{
		printf("\n");
		return (0);
	}
	ft_prime(n);
	return (0);
}