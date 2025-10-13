/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_v9.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:21:42 by elorente          #+#    #+#             */
/*   Updated: 2025/06/11 21:48:15 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/minishell.h"
#include "../libft/libft.h"
#include <dirent.h>
#include <sys/stat.h>

int	handle_dollar_loop(const char *line, char **res, t_expand_ctx *ctx)
{
	int		i;
	int		start;

	i = 0;
	start = 0;
	while (line[i])
	{
		if (line[i] == '$')
		{
			if (i > start && !expand_and_append(res, line, &start, i))
				return (0);
			if (line[i + 1] == '?')
			{
				*res = expand_exit_status(*res, ctx->exit_status);
				if (!*res)
					return (0);
				i += 2;
			}
			else
			{
				ctx->index = &i;
				*res = expand_variable_segment(*res, ctx);
				if (!*res)
					return (0);
				i = *(ctx->index);
			}
			start = i;
		}
		else
			i++;
	}
	if (i > start && !expand_and_append(res, line, &start, i))
		return (0);
	return (1);
}

char	*extract_variable_name(const char *str, int *consumed_len)
{
	int	i;

	if (!str || !consumed_len)
		return (empty_var_name(NULL));
	if (str[0] == '?')
	{
		*consumed_len = 1;
		return (ft_strdup("?"));
	}
	if (str[0] == '{')
	{
		i = 1;
		while (str[i] && str[i] != '}')
			i++;
		if (str[i] != '}')
			return (empty_var_name(consumed_len));
		*consumed_len = i + 1;
		return (ft_substr(str, 1, i - 1));
	}
	i = 0;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	if (i == 0)
		return (empty_var_name(consumed_len));
	*consumed_len = i;
	return (ft_substr(str, 0, i));
}
