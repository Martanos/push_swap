/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 00:31:58 by malee             #+#    #+#             */
/*   Updated: 2024/05/07 02:54:05 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_head(t_stack **stack)
{
	t_node	*first;
	t_node	*second;

	if ((*stack)->length > 1)
	{
		first = (*stack)->stack_head;
		second = first->next;
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		else
			(*stack)->stack_tail = first;
		second->prev = NULL;
		second->next = first;
		first->prev = second;
		(*stack)->stack_head = second;
	}
	update_stack(stack);
}

void	push(t_stack **src, t_stack **dest)
{
	t_node	*temp;

	update_stack(src);
	if ((*src)->length > 0)
	{
		temp = (*src)->stack_head;
		(*src)->stack_head = temp->next;
		if (temp->next)
			temp->next->prev = NULL;
		else
		{
			(*src)->stack_tail = NULL;
			(*src)->stack_head = NULL;
		}
		temp->next = (*dest)->stack_head;
		if ((*dest)->stack_head)
			(*dest)->stack_head->prev = temp;
		else
			(*dest)->stack_tail = temp;
		(*dest)->stack_head = temp;
	}
	update_stack(dest);
}

void	rotate(t_stack **stack)
{
	t_node	*temp;

	if ((*stack)->length > 1)
	{
		temp = (*stack)->stack_head;
		(*stack)->stack_head = temp->next;
		temp->next->prev = NULL;
		temp->next = NULL;
		temp->prev = (*stack)->stack_tail;
		(*stack)->stack_tail->next = temp;
		(*stack)->stack_tail = temp;
	}
	update_stack(stack);
}

void	reverse_rotate(t_stack **stack)
{
	t_node	*temp;

	if ((*stack)->length > 1)
	{
		temp = (*stack)->stack_tail;
		(*stack)->stack_tail = temp->prev;
		temp->prev->next = NULL;
		temp->prev = NULL;
		temp->next = (*stack)->stack_head;
		(*stack)->stack_head->prev = temp;
		(*stack)->stack_head = temp;
	}
	update_stack(stack);
}
