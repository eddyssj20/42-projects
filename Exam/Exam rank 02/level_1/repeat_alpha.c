/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:26:11 by elorente          #+#    #+#             */
/*   Updated: 2025/02/23 00:26:11 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void repeat_alpha(char *s)
{
	int		i = 0;
	int		j;
	int		repeat;
	char	c;

	while (s[i])
	{
		c = s[i];
		if (c >= 'a' && c <= 'z')
			repeat = c - 'a' + 1;
		else if (c >= 'A' && c <= 'Z')
			repeat = c - 'A' + 1;
		else
			repeat = 1;
		j = 0;
		while (j < repeat)
		{
			write(1, &c, 1);
			j++;
		}
		i++;
	}
	write (1, "\n", 1);
}

int	main (int argc, char *argv[])
{
	if(argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	repeat_alpha(argv[1]);
	return(0);
}