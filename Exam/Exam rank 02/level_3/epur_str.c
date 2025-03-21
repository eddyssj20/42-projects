/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:21:18 by elorente          #+#    #+#             */
/*   Updated: 2025/02/27 23:21:18 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_words(char *str)
{
	int i = 0;
	int j = 1;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (!j)
				write (1, " ", 1);
			j = 0;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
			{	
				write(1, &str[i], 1);
				i++;
			}
		}
		else
		i++;
	}
	write (1, "\n", 1);
}



int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_words(argv[1]);
	return (0);
}