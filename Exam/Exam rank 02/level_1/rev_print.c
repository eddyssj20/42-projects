/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:50:50 by elorente          #+#    #+#             */
/*   Updated: 2025/02/24 16:52:06 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void ft_rev_print(char *s)
{
	int	i = 0;

	i = ft_strlen(s);
	while (i > 0)
	{
		write (1, &s[i - 1], 1);
		i--;
	}
	write(1, "\n", 1);
}

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	ft_rev_print(argv[1]);
	return (0);
}