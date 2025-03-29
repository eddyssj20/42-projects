/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:25:23 by elorente          #+#    #+#             */
/*   Updated: 2025/03/29 18:34:28 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(t_data *data, int argc, char *argv[])
{
	int	i;
	int	num;

	data->sizea = 0;
	i = 1;
	while (i < argc)
	{
		if (numbers_mason(argv[i]) != 0)
		{
			ft_printf("Argumento invalido\n");
			// free necesario //
			exit (1);
		}
		num = ft_atoi(argv[i]);
		data->sa[data->sizea] = num;
		data->sizea++;
		i++;
	}
	if (check_nums(data) != 0)
	{
		ft_printf("Numeros repetidos\n");
		// free necesario //
		exit (1);
	}
	data->sizeb = 0;
}
