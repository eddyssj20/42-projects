/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:03:33 by elorente          #+#    #+#             */
/*   Updated: 2025/02/27 11:03:33 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_do_op(char *s1, char *op, char *s3)
{
	int	f;
	int	s;
	int	r = 0;

	f = atoi(s1);
	s = atoi(s3);

	if (op[0] == '+')
		r = f + s;
	else if (op[0] == '-')
		r = f - s;
	else if (op[0] == '*')
		r = f * s;
	else if (op[0] == '/')
		r = f / s;
	else if (op[0] == '%')
		r = f % s;
	printf("%d", r);
}

int main (int argc, char *argv[])
{
	if (argc !=  4)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_do_op(argv[1], argv[2], argv[3]);
	return (0);
}