/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:06:54 by elorente          #+#    #+#             */
/*   Updated: 2025/03/01 15:06:54 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void fill(char **tab, t_point size, int y, int x, char target)
{
	if (x < 0 || x >= size.x || y < 0 || y >= size.y || tab[y][x] != target)
		return;
	
	tab[y][x] = 'F';
	fill(tab, size, y + 1, x, target);
	fill(tab, size, y - 1, x, target);
	fill(tab, size, y, x + 1, target);
	fill(tab, size, y, x - 1, target);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;
	target = tab[begin.y][begin.x];
	fill(tab, size, begin.y, begin.x, target);
}
