/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:07:32 by elorente          #+#    #+#             */
/*   Updated: 2025/02/27 19:07:32 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int max(int *tab, unsigned int len)
{
	int i = 1;
	int max;

	if (len == 0);
		return (0);
	max = tab[0];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
	
}