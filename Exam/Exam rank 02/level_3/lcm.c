/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:54:18 by elorente          #+#    #+#             */
/*   Updated: 2025/03/02 11:54:18 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int hcf(unsigned int a, unsigned int b)
{
	while (b)
	{
		unsigned int temp;

		temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int	res;
	if ((a == 0) || (b == 0))
		return (0);
	res = ((a * b) / hcf(a, b));
	return (res);
}