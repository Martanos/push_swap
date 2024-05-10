/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:42:14 by malee             #+#    #+#             */
/*   Updated: 2024/05/10 14:34:17 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_ascended(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->stack_head)
		return (1);
	if (stack->length <= 1)
		return (0);
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

	if (!stack || !stack->stack_head)
		return (1);
	if (stack->length <= 1)
		return (0);
	current = stack->stack_head;
	while (current->next)
	{
		if (current->value < current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

t_node	*find_largest_node(t_stack **stack)
{
	t_node	*largest;
	t_node	*current;

	if (!stack || !(*stack)->stack_head)
		return (0);
	if ((*stack)->length == 1)
		return ((*stack)->stack_head);
	largest = (*stack)->stack_head;
	current = (*stack)->stack_head;
	while (current != NULL)
	{
		if (current->value > largest->value)
			largest = current;
		current = current->next;
	}
	return (largest);
}

t_node	*find_smallest_node(t_stack **stack)
{
	t_node	*smallest;
	t_node	*current;

	if (!stack || !(*stack)->stack_head)
		return (0);
	if ((*stack)->length == 1)
		return ((*stack)->stack_head);
	smallest = (*stack)->stack_head;
	current = (*stack)->stack_head;
	while (current != NULL)
	{
		if (current->value < smallest->value)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

t_node	*find_stack_tail(t_node *stack_head)
{
	if (stack_head == NULL)
		return (NULL);
	while (stack_head->next)
		stack_head = stack_head->next;
	return (stack_head);
}
