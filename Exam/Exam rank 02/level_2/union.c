/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:17:50 by elorente          #+#    #+#             */
/*   Updated: 2025/02/27 20:17:50 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int printed (char *s, char c, int pos)
{
	int i = 0;
	while (i < pos)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void ft_union(char *s1, char *s2)
{
	int	i = 0;
	int j = 0;
	
	while (s1[i])
	{
		if (!printed(s1, s1[i], i))
			write(1, &s1[i], 1);
		i++;
	}
	while (s2[j])
	{
		if (!printed(s1, s2[j], i) && !printed(s2, s2[j], j))
			write(1, &s2[j], 1);
		j++;
	}
	write (1, "\n", 1);
}

int main (int argc, char *argv[])
{
	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	ft_union(argv[1], argv[2]);
	return (0);
}