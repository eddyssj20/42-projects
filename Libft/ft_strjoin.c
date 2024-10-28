/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:46:34 by elorente          #+#    #+#             */
/*   Updated: 2024/10/07 13:03:23 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*uni;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	uni = (char *)malloc((len1 + len2 +1) * sizeof(char));
	if (!uni)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		uni[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		uni[i + j] = s2[j];
		j++;
	}
	uni[i + j] = '\0';
	return (uni);
}
