/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:20:11 by malee             #+#    #+#             */
/*   Updated: 2024/04/26 03:53:30 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_node(t_stack *stack, ssize_t value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		error();
	ft_memset(new_node, 0, sizeof(t_node));
	new_node->value = value;
	if (stack->length == 0)
	{
		stack->stack_head = new_node;
		stack->stack_tail = new_node;
	}
	else
	{
		new_node->prev = stack->stack_tail;
		stack->stack_tail->next = new_node;
		stack->stack_tail = new_node;
	}
	stack->length++;
	stack->is_sorted = 0;
}

void	free_nodes(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack->stack_head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
		temp = NULL;
	}
}
