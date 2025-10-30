/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:23:56 by elorente          #+#    #+#             */
/*   Updated: 2025/03/01 15:23:56 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range(int start, int end)
{
	int size;
	int	*range;
	int	i = 0;

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
			range[i] = start + i;
		else
			range[i] = start - i;
		i++;
	}
	return (range);
}