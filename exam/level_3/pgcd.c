/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:19:10 by elorente          #+#    #+#             */
/*   Updated: 2025/03/02 13:19:10 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int pgcd (int a, int b)
{
	int temp = 0;
	while (b)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

int main (int argc, char *argv[])
{
	int a = 0;
	int b = 0;

	if (argc != 3)
	{
		printf("\n");
		return (0);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	
	if (a <=  || b <= 0)
	{
		printf("\n");
		return (0);
	}
	printf("%d\n", pgcd(a,b));
	return (0);
}