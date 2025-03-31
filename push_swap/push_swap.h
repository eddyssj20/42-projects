/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:19:34 by elorente          #+#    #+#             */
/*   Updated: 2025/03/29 19:19:39 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"

typedef struct s_data
{
	int		*sa;
	int		*sb;
	int		sizea;
	int		sizeb;

}	t_data;

//swap.c//
void	swap(int *stack);
void	sa(int *a);
void	sb(int *b);
void	ss(int *a, int *b);
void	swap_int(int *a, int *b);

//push.c//
void	pa(t_data *data);
void	pb(t_data *data);

//rotate.c//
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

//reverse.c//
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

//numbers.c//

int		numbers_mason(char *s);
int		duplikate(t_data *data, int num, int j);
int		check_nums(t_data *data);

//parse.c//

void	parse_args(t_data *data, int argc, char *argv[]);

//sorter.c//

void	choose_sort(t_data *data);
void	sort_two(t_data *data);
void	sort_three(t_data *data);

//sort_five.c//

int		find_min(t_data *data):
void	push_min(t_data *data);
void	sort_five(t_data *data);

#endif