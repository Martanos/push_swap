/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:25:41 by malee             #+#    #+#             */
/*   Updated: 2024/05/11 02:46:55 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bring_largest_to_top(t_stack **stack)
{
	while ((*stack)->max_value != (*stack)->stack_head)
	{
		if ((*stack)->max_value->position >= (*stack)->length / 2)
			rrb(stack);
		else
			rb(stack);
	}
}

static void	initial_push(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_b)->length < 3)
		pb(stack_a, stack_b);
	tiny_sort_desc(stack_b);
}

static void	parser(t_node *current, t_stack **stack_a, t_stack **stack_b)
{
	// if ((*stack_a)->length > 2)
	// {
	// 	if (current != (*stack_a)->stack_head
	// 		&& current->target_node != (*stack_b)->stack_head)
	// 	{
	// 		if (current->position <= (*stack_a)->length / 2
	// 			&& current->target_node->position <= (*stack_b)->length / 2)
	// 			rr(stack_a, stack_b);
	// 		else if (current->position >= (*stack_a)->length / 2
	// 			&& current->target_node->position >= (*stack_b)->length / 2)
	// 			rrr(stack_a, stack_b);
	// 	}
	// }
	if (current != (*stack_a)->stack_head)
	{
		if (current->position <= (*stack_a)->length / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	else if (current->target_node != (*stack_b)->stack_head)
	{
		if (current->target_node->position <= (*stack_b)->length / 2)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

static void	move_node(t_node *current, t_stack **stack_a, t_stack **stack_b)
{
	while (current != (*stack_a)->stack_head
		|| current->target_node != (*stack_b)->stack_head)
		parser(current, stack_a, stack_b);
	pb(stack_a, stack_b);
	set_prices(stack_a, stack_b);
}

void	sort_lists(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*current;

	initial_push(stack_a, stack_b);
	while ((*stack_a)->length > 0)
	{
		set_prices(stack_a, stack_b);
		current = (*stack_a)->stack_head;
		while (current)
		{
			if (current->cheapest == 1)
			{
				move_node(current, stack_a, stack_b);
				break ;
			}
			current = current->next;
		}
	}
	bring_largest_to_top(stack_b);
	while ((*stack_b)->length > 0)
		pa(stack_b, stack_a);
}
// 9 10 3 5 7 2 1 8 4 6
