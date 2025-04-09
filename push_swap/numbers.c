/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:07:40 by elorente          #+#    #+#             */
/*   Updated: 2025/03/29 18:22:37 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	numbers_mason(char *s)
{
	int	i;
	
	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] == '\0')
		return (-1);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return 	(-1);
		i++;
	}
	return (0);
}

int	duplikate(t_data *data, int num, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (data->sa[i] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_nums(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->sizea)
	{
		if (!duplikate(data, data->sa[i], i))
			return (-1);
		i++;
	}
	return (0);
}
