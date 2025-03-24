/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:19:11 by elorente          #+#    #+#             */
/*   Updated: 2025/03/24 11:23:33 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	push(t_stack **stack, int value)
{
	t_stack	*node;
	
	node = new_node(value);
	if (!node)
		return ;
	node->next = *stack;
	*stack = node;
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

void free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*stack = NULL;
}

int	main(int argc, char *argv[])
{
	t_stack *stack_a;
	int		i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		push(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	ft_printf("Stack a:\n");
	print_stack(stack_a);

	free_stack(&stack_a);
	return (0);
}
