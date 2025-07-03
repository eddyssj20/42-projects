/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:02:04 by elorente          #+#    #+#             */
/*   Updated: 2025/06/27 18:01:58 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philo.h"

int	all_philos_have_eaten(t_data *data)
{
	int	i;

	if (data->meals_required == -1)
		return (0);
	i = 0;
	while (i < data->num_philos)
	{
		if (data->philos[i].meals_eaten < data->meals_required)
			return (0);
		i++;
	}
	return (1);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!data->sim_end)
	{
		i = 0;
		while (i < data->num_philos)
		{
			if ((get_time_in_ms() - data->philos[i].last_meal)
				> data->time_to_die)
			{
				pthread_mutex_lock(&data->print_mutex);
				printf("%ld %d pal lobby\n",
					get_time_in_ms() - data->start_time, data->philos[i].id);
				data->sim_end = 1;
				return (pthread_mutex_unlock(&data->print_mutex), NULL);
			}
			i++;
		}
		if (all_philos_have_eaten(data))
			return (data->sim_end = 1, NULL);
		usleep(1000);
	}
	return (NULL);
}
