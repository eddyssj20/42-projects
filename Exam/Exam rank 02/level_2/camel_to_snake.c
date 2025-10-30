/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:08:16 by elorente          #+#    #+#             */
/*   Updated: 2025/02/24 19:23:15 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_cts(char *s)
{
	int	i = 0;
	char	c;
	char	u;

	while (s[i])
	{
		c = s[i + 1];
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			write(1, "_", 1);
			c = s[i] + 32;
			write (1, &c, 1);
		}
		else
			write(1, &s[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	ft_cts(argv[1]);
	return (0);
}