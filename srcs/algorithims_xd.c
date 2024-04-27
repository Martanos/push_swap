/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithims_xd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:25:41 by malee             #+#    #+#             */
/*   Updated: 2024/04/27 09:41:00 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort_algorithim(t_stack *stack_a, t_stack *stack_b)
{
	while (!stack_a->is_sorted)
	{
		if (stack_a->stack_head->value > stack_a->stack_head->next->value)
		{
			swap_head(stack_a);
			stack_a->is_sorted = 1;
		}
		if (!stack_a->is_sorted)
			push(stack_a, stack_b);
	}
	while (stack_b->length > 0)
		push(stack_b, stack_a);
}

void	selection_sort_algorithim(t_stack *stack_a, t_stack *stack_b)
{
}
