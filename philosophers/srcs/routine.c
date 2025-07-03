/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:39:40 by elorente          #+#    #+#             */
/*   Updated: 2025/06/27 18:04:25 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philo.h"

void	take_forks(t_philosopher *philo)
{
	if (philo->data->sim_end)
		return ;
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "Tomo un tenedor... tiene hambre");
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "Tomo otro tenedor... se esta muriendo de hambre");
}

void	eat(t_philosopher *philo)
{
	long	timestamp;

	if (philo->data->sim_end)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	philo->last_meal = get_time_in_ms();
	philo->meals_eaten++;
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->sim_end)
	{
		timestamp = get_time_in_ms() - philo->data->start_time;
		printf("%ld philo %d ñom ñom ñom (esta comiendo %d)\n",
			timestamp, philo->id, philo->meals_eaten);
	}
	if (all_philos_have_eaten(philo->data))
		philo->data->sim_end = 1;
	pthread_mutex_unlock(&philo->data->print_mutex);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleep_and_think(t_philosopher *philo)
{
	if (philo->data->sim_end)
		return ;
	print_status(philo, "Zzzzzzzzzzzzzzzz");
	usleep(philo->data->time_to_sleep * 1000);
	print_status(philo, "Esta pensando quien es mas fuerte Gogetta o Veggeto");
}
