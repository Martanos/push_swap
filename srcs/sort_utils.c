/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:25:41 by malee             #+#    #+#             */
/*   Updated: 2024/05/10 13:41:39 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bring_largest_to_top(t_stack **stack)
{
	while ((*stack)->max_value != (*stack)->stack_head)
	{
		if ((*stack)->max_value->value < (*stack)->length / 2)
			rb(stack);
		else
			rrb(stack);
		update_stack(stack);
	}
}

static void	bring_target_to_top(t_node *target, t_stack **stack_b)
{
	while (target != (*stack_b)->stack_head)
	{
		if (target->position < (*stack_b)->length / 2)
			rb(stack_b);
		else
			rrb(stack_b);
		update_stack(stack_b);
	}
}

static void	push_from_a(t_node *current, t_stack **stack_a, t_stack **stack_b)
{
	while (current != (*stack_a)->stack_head)
	{
		if (current->position < (*stack_a)->length / 2)
			ra(stack_a);
		else
			rra(stack_a);
		update_stack(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_lists(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*current;

	while ((*stack_b)->length < 3)
		pb(stack_a, stack_b);
	tiny_sort_desc(stack_b);
	while ((*stack_a)->length > 1)
	{
		set_prices(stack_a, stack_b);
		current = (*stack_a)->stack_head;
		while (current)
		{
			if (current->cheapest == 1 && current != (*stack_a)->max_value)
			{
				bring_target_to_top(current->target_node, stack_b);
				push_from_a(current, stack_a, stack_b);
				break ;
			}
			current = current->next;
		}
	}
	bring_largest_to_top(stack_b);
	while ((*stack_b)->length > 0)
		pa(stack_b, stack_a);
}
