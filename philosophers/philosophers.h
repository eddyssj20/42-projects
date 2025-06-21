/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:22:29 by elorente          #+#    #+#             */
/*   Updated: 2025/06/21 19:22:29 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread;
	long			last_meal;
	int				meals_eaten;
	struct s_data	*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philosopher;

typedef struct s_data
{
	int				num_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				meals_required;
	int				sim_end;
	long			start_time;
	t_philosopher	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
}	t_data;

#endif