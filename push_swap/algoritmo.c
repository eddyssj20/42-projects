/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:15:31 by elorente          #+#    #+#             */
/*   Updated: 2025/04/05 19:15:31 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_value(t_data *data)
{
	int	*sorted;

	sorted = malloc(sizeof(int) * data->sizea)
	if (!sorted)
		//free//
	copy_array(sorted, data->sa, data->sizea);
	array_order(sorted, data->sizea);
	replace_index(data, sorted);
	free(sorted);
}

void	copy_array(int *dest, int *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

void	array_order(int *arr, int *size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	replace_index(t_data *data, int *sorted)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->sizea)
	{
		j = 0;
		while (j < data->sizea)
		{
			if (data->sa[i] == sorted[j])
			{
				data->sa[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	find_max(t_data *data)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	index = 0;
	max = data->sb[0];
	while (i < data->sizeb)
	{
		if (data->sb[i] > max)
		{
			max = data->sb[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	push_biggest(t_data *data)
{
	int	index;

	index = find_max(data);
	if (index < data->sizeb/2)
	{
		while (index-- > 0)
			rb(data);
	}
	else
	{
		while (index++ < data->sizeb)
			rrb(data);
	}
	pa(data);
}

void	chunk_sort(t_data *data)
{
	int	chunks;
	int	chunk_size;
	int	chunk_limit;
	int	pushed;

	chunks = 5;
	chunk_size = data->sizea / chunks;
	chunk_limit = chunk_size;
	pushed = 0;
	index_value(data);
	while (pushed < data->sizea)
	{
		if (data->sa[0] < chunk_limit)
		{
			pb(data);
			pushed++;
		}
		else
			ra(data);
		if (pushed == chunk_limit)
			chunk_limit += chunk_size;
	}
	while (data->sizeb > 0)
		push_biggest(data);
}
