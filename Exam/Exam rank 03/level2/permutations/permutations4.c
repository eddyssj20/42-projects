/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:46:47 by elorente          #+#    #+#             */
/*   Updated: 2025/11/04 16:58:43 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int	all_alpha(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || str[i] >= 'A' && str[i] <= 'Z'))
			return(1);
		i++;
	}
	return(0);
}

void	swap(char *s1, char *s2)
{
	char temp;
	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	order(char *str)
{
	int	i = 0;
	int swapped = 1;
	
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (str[i + 1])
		{
			if (str[i] > str[i + 1])
			{
				swap(&str[i], &str[i + 1]);
				swapped = 1;
			}
			i++;
		}
	}
}

void	permutate(char *str, int start, int len)
{
	if (start == (len - 1))
	{
		write(1, str, len);
		write(1, "\n", 1);
	}

	else
	{
		int i = start;
		while (i < len)
		{
			swap(&str[start], &str[i]);
			permutate(str, start + 1, len);
			swap(&str[start], &str[i]);
			i++;
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2 || all_alpha(argv[1]))
		return(1);
	int len = ft_strlen(argv[1]);
	order(argv[1]);
	permutate(argv[1], 0, len);
	return (0);
}