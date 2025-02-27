/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:05:57 by elorente          #+#    #+#             */
/*   Updated: 2025/02/27 14:05:57 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strdup(char *src)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = 0;
	while (src[len] != '\0')
		len++;
	dup = (char *)malloc((len + 1) *sizeof(char));
	if (dup == NULL)
		return(NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}