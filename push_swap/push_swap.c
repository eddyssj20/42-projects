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
	t_data	*data;
	int		total;

	if (argc < 2)
		return (0);
	total = count_numbers(argc, argv);
	if (total <= 0)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		free_for_all(data, 1);
	data->sa = malloc(sizeof(int) * total);
	data->sb = malloc(sizeof(int) * total);
	if (!data->sa || !data->sb)
		free_for_all(data, 1);
	parse_args(data, argc, argv);
	if (is_sorted(data))
		free_for_all(data, 0);
	choose_sort(data);
	if (!is_sorted(data))
		free_for_all(data, 1);
	free_for_all(data, 0);
	return (0);
}
