/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:13:08 by elorente          #+#    #+#             */
/*   Updated: 2025/03/29 17:48:15 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	int	i;

	i = 0;
	while (i + 1 < data->sizea)
	{
		swap_int(&data->sa[i], &data->sa[i + 1]);
		i++;
	}
	ft_printf("ra\n");
}

void	rb(t_data *data)
{
	int	i;

	i = 0;
	while (i + 1 < data->sizeb)
	{
		swap_int(&data->sb[i], &data->sb[i + 1]);
		i++;
	}
	ft_printf("rb\n");
}

void	rr(t_data *data)
{
	int	i;

	i = 0;
	while (i + 1 < data->sizea)
	{
		swap_int(&data->sa[i], &data->sa[i + 1]);
		i++;
	}
	i = 0;
	while (i + 1 < data->sizeb)
	{
		swap_int(&data->sb[i], &data->sb[i + 1]);
		i++;
	}
	ft_printf("rr\n");
}
