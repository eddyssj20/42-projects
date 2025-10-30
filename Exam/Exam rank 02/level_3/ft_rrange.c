/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:01:36 by elorente          #+#    #+#             */
/*   Updated: 2025/03/01 16:01:36 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_rrange(int start, int end)
{
	int	i = 0;
	int size;
	int *range;

	if (start <= end)
		size = end - start + 1;
	else
		size = start - end + 1;
	range = (int *)malloc(sizeof(int) * size);
	if (!range)
		return (NULL);
	while (i < size)
	{
		if (start <= end)
			range[i] = end - i;
		else
			range[i] = end + i;
		i++;
	}
	return (range);
}