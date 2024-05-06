/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:42:14 by malee             #+#    #+#             */
/*   Updated: 2024/05/07 01:32:55 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_ascended(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->stack_head || stack->length <= 1)
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

	if (!stack || !stack->stack_head || stack->length <= 1)
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

ssize_t	find_largest(t_stack *stack)
{
	ssize_t	largest;
	t_node	*current;

	if (!stack || !stack->stack_head)
		return (1);
	largest = stack->stack_head->value;
	current = stack->stack_head->next;
	while (current != NULL)
	{
		if (current->value > largest)
			largest = current->value;
		current = current->next;
	}
	return (largest);
}

ssize_t	find_smallest(t_stack *stack)
{
	ssize_t	smallest;
	t_node	*current;

	if (!stack || !stack->stack_head)
		return (1);
	smallest = stack->stack_head->value;
	current = stack->stack_head->next;
	while (current != NULL)
	{
		if (current->value < smallest)
			smallest = current->value;
		current = current->next;
	}
	return (smallest);
}

ssize_t	find_position(t_stack *stack, ssize_t value)
{
	ssize_t	position;
	t_node	*current;

	if (!stack || !stack->stack_head)
		return (-1);
	position = 1;
	current = stack->stack_head;
	while (current != NULL)
	{
		if (current->value == value)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}
