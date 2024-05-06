/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 03:35:11 by malee             #+#    #+#             */
/*   Updated: 2024/05/06 20:57:17 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack, char **argv)
{
	ssize_t	value;

	value = 0;
	if (*stack)
	{
		free_nodes(*stack);
		free(*stack);
	}
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (!*stack)
		error();
	ft_memset(*stack, 0, sizeof(t_stack));
	if (argv)
	{
		while (*argv)
		{
			value = ft_atoi(*argv);
			init_node(*stack, atoi(*argv++));
			if (value < (*stack)->min_value)
				(*stack)->min_value = value;
			if (value > (*stack)->max_value)
				(*stack)->max_value = value;
		}
		(*stack)->is_sorted = is_sorted(*stack);
	}
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*current_b;

	current_a = stack_a->stack_head;
	current_b = stack_b->stack_head;
	ft_printf("-------------------------------\n%s\n");
	while (current_a || current_b)
	{
		if (current_a)
		{
			ft_printf("%ld", current_a->value);
			current_a = current_a->next;
		}
		else
			ft_printf(" ");
		if (current_b)
		{
			ft_printf(" %ld\n", current_b->value);
			current_b = current_b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("_ _\na b\n-------------------------------\n");
}

int	is_sorted_ascended(t_stack *stack)
{
	t_node	*current;

	if (stack->length <= 1)
		return (1);
	current = stack->stack_head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_sorted_descended(t_stack *stack)
{
	t_node	*current;

	if (stack->length <= 1)
		return (1);
	current = stack->stack_head;
	while (current->next)
	{
		if (current->value < current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
