/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:19:42 by malee             #+#    #+#             */
/*   Updated: 2024/05/08 18:21:48 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_head(t_stack **stack)
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

void	sa(t_stack **stack_a)
{
	swap_head(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap_head(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_head(stack_a);
	swap_head(stack_b);
	ft_printf("ss\n");
}
