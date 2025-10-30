/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:38:21 by elorente          #+#    #+#             */
/*   Updated: 2025/02/24 18:15:01 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	

void ft_snr(char *str, char s, char r)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == s)
			write(1, &r, 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int main(int argc, char *argv[])
{
	if (argc != 4 || argv[2][1] || argv[3][1])
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_snr(argv[1], argv[2][0], argv[3][0]);
	return (0);
}