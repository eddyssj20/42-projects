/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:25:29 by elorente          #+#    #+#             */
/*   Updated: 2025/03/29 17:47:48 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	int	i;

	i = data->sizea - 1;
	while (i > 0)
	{
		swap_int(&data->sa[i], &data->sa[i - 1]);
		i--;
	}
	ft_printf("rra\n");
}

void	rrb(t_data *data)
{
	int	i;

	i = data->sizeb - 1;
	while (i > 0)
	{
		swap_int(&data->sb[i], &data->sb[i - 1]);
		i--;
	}
	ft_printf("rrb\n");
}

void	rrr(t_data *data)
{
	int	i;

	i = data->sizea - 1;
	while (i > 0)
	{
		swap_int(&data->sa[i], &data->sa[i - 1]);
		i--;
	}
	i = data->sizeb - 1;
	while (i > 0)
	{
		swap_int(&data->sb[i], &data->sb[i - 1]);
		i--;
	}
	ft_printf("rrr\n");
}
