/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:19:11 by elorente          #+#    #+#             */
/*   Updated: 2025/03/29 19:10:51 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data *data;
	
	if (argc < 2)
	{
		ft_printf("Faltan argumentos\n");
		return (0);
	}
	data = malloc(sizeof(t_data));
	if (!data)
	{
		ft_printf("Error de memoria\n");
		return (0);
	}
	data->sa = malloc(sizeof(int) * (argc - 1));
	data->sb = malloc(sizeof(int) * (argc - 1));
	if (!data->sa || data->sb)
	{
		ft_printf("Error de memoria en sa o sb\n");
		return (1);
	}
	parse_args(&data, argc, argv);
	choose_sort(data);
	// faltan free //
	return (0);
}
