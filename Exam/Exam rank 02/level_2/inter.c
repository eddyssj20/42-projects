/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:23:16 by elorente          #+#    #+#             */
/*   Updated: 2025/02/27 18:23:16 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int printed(char *str, char c, int pos)
{
	int i = 0;
	while (i < pos)
	{
		if (str[i] == c)
			return(1);
		i++;
	}
	return (0);
}

void ft_inter(char *s1, char *s2)
{
	int i = 0;
	int j;
	
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				if(!printed(s1, s1[i], i))
				{
					write (1, &s1[i], 1);
					break;
				}
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int main (int argc, char *argv[])
{
	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	ft_inter(argv[1], argv[2]);
	return (0);
}