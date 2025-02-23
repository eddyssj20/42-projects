/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 23:09:02 by elorente          #+#    #+#             */
/*   Updated: 2025/02/22 23:09:02 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_first_word(char *str)
{
	int	i;
	i = 0;
	while (str[i] == ' '|| str[i] == '\t')
		i++;
	while(str[i] && str[i] != ' ' && str[i] != '\t')
	{	
		write(1, &str[i], 1);
		i++;
	}
	write (1, "\n", 1);
	return (0);
}

int main (int argc,char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return(0);
	}
	ft_first_word(argv[1]);
	return (0);
}