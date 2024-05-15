/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 03:35:11 by malee             #+#    #+#             */
/*   Updated: 2024/05/15 23:32:17 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack, char **argv)
{
	if (*stack)
	{
		free_nodes(stack);
		free(*stack);
	}
	*stack = (t_stack *)malloc(sizeof(t_stack) + 1);
	if (!*stack)
		error();
	ft_memset(*stack, 0, sizeof(t_stack));
	if (argv)
	{
		while (*argv)
		{
			init_node(stack, atoi(*argv++));
			update_stack(stack);
		}
	}
	update_stack(stack);
}

size_t	get_stack_length(t_stack *stack)
{
	size_t	length;
	t_node	*current;

	length = 0;
	current = stack->stack_head;
	while (current != NULL)
	{
		length++;
		current = current->next;
	}
	return (length);
}

void	update_stack(t_stack **stack)
{
	ssize_t	position;
	t_node	*current;

	position = 0;
	if (!stack)
		error();
	else if ((*stack)->stack_head == NULL)
		ft_memset(*stack, 0, sizeof(t_stack));
	else
	{
		(*stack)->length = get_stack_length(*stack);
		(*stack)->is_sorted_asc = is_sorted_ascended(*stack);
		(*stack)->is_sorted_desc = is_sorted_descended(*stack);
		(*stack)->min_value = find_smallest_node(stack);
		(*stack)->max_value = find_largest_node(stack);
		(*stack)->stack_tail = find_stack_tail((*stack)->stack_head);
		current = (*stack)->stack_head;
		while (current)
		{
			current->position = position;
			position++;
			current = current->next;
		}
	}
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	free_nodes(stack_a);
	free(*stack_a);
	free_nodes(stack_b);
	free(*stack_b);
}

// void	print_stacks(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_node	*current_a;
// 	t_node	*current_b;

// 	current_a = (*stack_a)->stack_head;
// 	current_b = (*stack_b)->stack_head;
// 	ft_printf("-------------------------------\n");
// 	while (current_a || current_b)
// 	{
// 		if (current_a)
// 		{
// 			ft_printf("%ld", current_a->value);
// 			current_a = current_a->next;
// 		}
// 		else
// 			ft_printf(" ");
// 		if (current_b)
// 		{
// 			ft_printf(" %ld\n", current_b->value);
// 			current_b = current_b->next;
// 		}
// 		else
// 			ft_printf("\n");
// 	}
// 	ft_printf("_ _\na b\n-------------------------------\n");
// }
