/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:16:16 by elorente          #+#    #+#             */
/*   Updated: 2025/02/24 18:25:16 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_ulstr(char *s)
{
	int i = 0;
	char c;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			c = s[i] + 32;
			write(1, &c, 1);
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			c = s[i] - 32;
			write(1, &c, 1);
		}
		else
			write(1, &s[i], 1);
		i++;
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
	ft_ulstr(argv[1]);
	return (0);
}