/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:19:34 by elorente          #+#    #+#             */
/*   Updated: 2025/03/24 11:04:19 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"

typedef struct s_stack
{
	int		value;
	struct	s_stack *next;
} t_stack;

//swap.c//
void	swap(int *stack);
void	sa(int *a);
void	sb(int *b);
void	ss(int *a, int *b);
void	swap_int(int *a, int *b);

//push.c//
void	pa(t_list *data);
void	pb(t_list *data);

//rotate.c//
void	ra(t_list *data);
void	rb(t_list *data);
void	rr(t_list *data);

//reverse.c//
void	rra(t_list *data);
void	rrb(t_list *data);
void	rrr(t_list *data);

#endif