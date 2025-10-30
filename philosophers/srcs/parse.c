/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:45:50 by elorente          #+#    #+#             */
/*   Updated: 2025/06/22 18:45:50 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philo.h"

int	parse_arguments(int argc, char *argv[], t_data *data)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (!is_digit_str(argv[i]))
			return (1);
		i++;
	}
	data->num_philos = (int)ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->meals_required = -1;
	if (argc == 6)
		data->meals_required = (int)ft_atol(argv[5]);
	data->sim_end = 0;
	return (0);
}
