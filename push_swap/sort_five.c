/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:19:19 by elorente          #+#    #+#             */
/*   Updated: 2025/03/29 19:27:19 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_data *data)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = data->sa[0];
	index = 0;
	while(i < data->sizea)
	{
		if (data->sa[i] < min)
		{
			min = data->sa[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	push_min(t_data *data)
{
	int	index;

	index = find_min(data);
	if (index == 1)
		ra(data);
	else if (index == 2)
	{
		ra(data);
		ra(data);
	}
	else if (index == 3 && data->sizea == 5)
	{
		rra(data);
		rra(data);
	}
	else if (index == 4 && data->sizea == 5)
		rra(data);
	pb(data);
}

void	sort_five(t_data *data)
{
	while (data->sizea > 3)
		push_min(data);
	sort_three(data);
	while (data->sizeb > 0)
		pa(data);
}
