/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:43:11 by elorente          #+#    #+#             */
/*   Updated: 2025/02/27 11:43:11 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	while (s[i])
	{
		size_t j = 0;
		while (reject[j])
		{
			if(s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}