/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:51:13 by elorente          #+#    #+#             */
/*   Updated: 2025/02/27 18:51:13 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_last_word(char *s)
{
	int	i = 0;
	int w;
	while (str[i])
		i++;
	i--;
	while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
		i--;
	w = i;
	while (i >= 0 && (str[i] != ' ' || str[i] == '\t'))
		i--;
	i++;
	while (i <= w)
	{
		write (1, &str[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		write (1, '\n', 1);
		return (0);
	}
	ft_last_word(argv[1]);
	return (0);
}