/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:25:41 by malee             #+#    #+#             */
/*   Updated: 2024/05/14 23:14:14 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bring_largest_to_top(t_stack **stack)
{
	while ((*stack)->min_value != (*stack)->stack_head)
	{
		if ((*stack)->min_value->position < (*stack)->length / 2)
			ra(stack);
		else
			rra(stack);
	}
}

static void	initial_push(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->length > 3)
	{
		if ((*stack_a)->stack_head == (*stack_a)->min_value
			|| (*stack_a)->stack_head == (*stack_a)->max_value)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	tiny_sort_asc(stack_a);
}

static void	parser(t_node *current, t_stack **stack_a, t_stack **stack_b)
{
	size_t	b_position;
	size_t	a_length;
	size_t	b_length;
	size_t	target_position;

	b_position = current->position;
	a_length = (*stack_a)->length;
	b_length = (*stack_b)->length;
	target_position = current->target_node->position;
	// Move the current node to the top of stack B
	if (b_position <= (b_length / 2))
	{
		if (target_position <= (a_length / 2))
		{
			// Use combined move rr
			while (b_position && target_position)
			{
				rr(stack_a, stack_b);
				b_position--;
				target_position--;
			}
		}
		while (b_position--)
			rb(stack_b);
	}
	else
	{
		if (target_position > (a_length / 2))
		{
			// Use combined move rrr
			while (b_length - b_position && a_length - target_position)
			{
				rrr(stack_a, stack_b);
				b_length--;
				a_length--;
			}
		}
		while (b_length - b_position)
		{
			rrb(stack_b);
			b_length--;
		}
	}
	// Move the target node to the top of stack A
	if (target_position <= (a_length / 2))
	{
		while (target_position--)
			ra(stack_a);
	}
	else
	{
		while (a_length - target_position)
		{
			rra(stack_a);
			a_length--;
		}
	}
	pa(stack_b, stack_a);
}

void	sort_lists(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*current;

	initial_push(stack_a, stack_b);
	while ((*stack_b)->length > 0)
	{
		set_prices(stack_a, stack_b);
		current = (*stack_b)->stack_head;
		while (current)
		{
			if (current->cheapest == 1)
			{
				parser(current, stack_a, stack_b);
				break ;
			}
			current = current->next;
		}
	}
	bring_largest_to_top(stack_a);
}
