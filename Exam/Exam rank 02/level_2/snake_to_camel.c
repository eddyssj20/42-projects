/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:02:33 by elorente          #+#    #+#             */
/*   Updated: 2025/02/27 20:02:33 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_stc(char *s)
{
	int		i = 0;
	char	c;
	while (s[i])
	{
		if (s[i] == '_')
		{
			i++;
			if(s[i])
			{
				c = s[i] - 32;
				write (1, &c, 1);
			}
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
		return (0);
	ft_stc(argv[1]);
	return (0);
}