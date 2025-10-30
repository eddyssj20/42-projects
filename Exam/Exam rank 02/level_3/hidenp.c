/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:48:56 by elorente          #+#    #+#             */
/*   Updated: 2025/03/01 16:48:56 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_hide(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;

	while(s1[i])
	{
		while (s2[j] && s2[j] != s1[i])
			j++;
		if (!s2[j])
		{
			write (1, "0\n", 2);
			return;
		}
		j++;
		i++;
	}
	write(1, "1", 1);
	write(1, "\n", 1);
}

int main (int argc, char *argv[])
{
	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	ft_hide(argv[1], argv[2]);
	retrun (0);
}