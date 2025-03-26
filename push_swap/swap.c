/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:25:15 by elorente          #+#    #+#             */
/*   Updated: 2025/03/26 19:25:15 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	sa(int *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(int *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(int *a, int *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}