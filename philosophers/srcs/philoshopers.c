/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoshopers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:23:50 by elorente          #+#    #+#             */
/*   Updated: 2025/06/21 19:23:50 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (parse_arguments(argc, argv, &data) != 0)
		return (error_msg("Error: argumentos invalidos\n"));
	if (init_data(&data) != 0)
		return (error_msg("Error: fallo inicializacion\n"));
	if (start_philo(&data) != 0)
		return (error_msg("Error: fallo Philo\n"));
	cleanup(&data);
	return (0);
}
