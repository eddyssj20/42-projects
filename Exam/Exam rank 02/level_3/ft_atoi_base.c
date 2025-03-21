/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:10:17 by elorente          #+#    #+#             */
/*   Updated: 2025/02/28 19:10:17 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int char_to_int(char c)
{
	if(c >= '0' && c <= '9')
		return(c - '0');
	if(c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if(c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}
int ft_atoi_base(const char *str, int str_base)
{
	if (!str || str_base < 2 || str_base > 16)
		return (0);

	int	res = 0;
	int sign = 1;
	int	i = 0;
	int value;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while(str[i])
	{
		value = char_to_int(str[i]);
		if (value < 0 || value >=str_base)
			break;
		res = res * str_base + value;
		i++;
	}
	return (res * sign);
}