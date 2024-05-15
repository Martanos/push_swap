/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:39:12 by malee             #+#    #+#             */
/*   Updated: 2024/05/16 00:19:40 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort_asc(t_stack **stack)
{
	while ((*stack)->stack_tail != (*stack)->max_value)
	{
		if ((*stack)->max_value == (*stack)->stack_head)
			ra(stack);
		else
			rra(stack);
	}
	if ((*stack)->stack_head->next
		&& (*stack)->stack_head->value > (*stack)->stack_head->next->value)
		sa(stack);
}

void	tiny_sort_desc(t_stack **stack)
{
	while ((*stack)->stack_tail != (*stack)->min_value)
	{
		if ((*stack)->min_value == (*stack)->stack_head)
			rb(stack);
		else
			rrb(stack);
	}
	if ((*stack)->stack_head->value < (*stack)->stack_head->next->value)
		sb(stack);
}
