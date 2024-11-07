/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:20:22 by elorente          #+#    #+#             */
/*   Updated: 2024/10/29 20:20:22 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	char			*str_buf;
	struct s_list	*next;
} t_list;

int		len_newline(t_list *list)
int		newline(t_list *list);
t_list	*find_last(t_list *list);
void	copy_str(t_list *list, char *str);


#endif