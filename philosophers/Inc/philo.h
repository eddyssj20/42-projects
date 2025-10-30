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

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
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

//parse.c

int		parse_arguments(int argc, char *argv[], t_data *data);

//utils.c

int		is_digit_str(char *str);
long	ft_atol(const char *str);
int		error_msg(char *msg);
int		ft_strlen(char *str);
void	print_status(t_philosopher *philo, char *msg);

//cleanup.c

void	cleanup(t_data *data);

//data.c

int		init_data(t_data *data);
int		init_forks(t_data *data);
void	init_philos(t_data *data);

//monitor.c

int		all_philos_have_eaten(t_data *data);
void	*monitor_routine(void *arg);

//routine.c

void	take_forks(t_philosopher *philo);
void	eat(t_philosopher *philo);
void	sleep_and_think(t_philosopher *philo);

//sim.c

long	get_time_in_ms(void);
void	*philosopher_routine(void *arg);
int		start_simulation(t_data *data);

#endif