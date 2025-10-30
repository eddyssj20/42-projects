/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:46:34 by elorente          #+#    #+#             */
/*   Updated: 2024/10/09 13:26:41 by elorente         ###   ########.fr       */
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

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	uni = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!uni)
		return (NULL);
	while (s1[i++])
		ft_memcpy(uni, s1, len1);
	while (s2[j++])
		ft_memcpy(len1 + uni, s2, len2);
	return (uni);
}
