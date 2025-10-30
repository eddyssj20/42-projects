/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:31:19 by elorente          #+#    #+#             */
/*   Updated: 2025/02/27 20:31:19 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_w (char *s1, char *s2)

{
	int i = 0;
	int j = 0;

	while (s1[i])
	{
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				i++;
				break;
			}
			j++;
		}
		if (!s2[j])
		{
			write(1, "\n", 1);
			return;
		}
	}
	write (1, s1, i);
	write (1, "\n", 1);
}

int main (int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_w(argv[1], argv[2]);
	return (0);
}