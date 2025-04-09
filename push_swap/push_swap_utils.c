/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:45:05 by elorente          #+#    #+#             */
/*   Updated: 2025/04/09 23:45:05 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_for_all(t_data *data, int error)
{
	if (data)
	{
		if (data->sa)
			free(data->sa);
		if (data->sb)
			free(data->sb);
		free (data);
	}
	if (error)
		write (2, "Error\n", 6);
	exit (error);
}

//a;adir error handlin//