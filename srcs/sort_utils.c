/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:25:41 by malee             #+#    #+#             */
/*   Updated: 2024/05/15 00:18:56 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parser_move_node_to_top_b(t_stack **stack_b, size_t b_position)
{
	size_t	b_length;

	b_length = (*stack_b)->length;
	if (b_position <= (b_length / 2))
	{
		while (b_position)
		{
			rb(stack_b);
			(b_position)--;
		}
	}
	else
	{
		while (b_length - b_position)
		{
			rrb(stack_b);
			(b_length)--;
		}
	}
}

static void	parser_move_node_to_top_a(t_stack **stack_a, size_t target_position)
{
	size_t	a_length;

	a_length = (*stack_a)->length;
	if (target_position <= (a_length / 2))
	{
		while (target_position)
		{
			ra(stack_a);
			target_position--;
		}
	}
	else
	{
		while (a_length - target_position)
		{
			rra(stack_a);
			(a_length)--;
		}
	}
}

static void	parser_moves_combined(t_stack **stack_a, t_stack **stack_b,
		size_t b_position, size_t target_position)
{
	size_t	a_length;
	size_t	b_length;

	a_length = (*stack_a)->length;
	b_length = (*stack_b)->length;
	if (b_position <= (b_length / 2) && target_position <= (a_length / 2))
	{
		while (b_position && target_position)
		{
			rr(stack_a, stack_b);
			b_position--;
			target_position--;
		}
	}
	else if (b_position > (b_length / 2) && target_position > (a_length / 2))
	{
		while (b_length - b_position && a_length - target_position)
		{
			rrr(stack_a, stack_b);
			b_length--;
			a_length--;
		}
	}
}

static void	parser(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*current;

	while ((*stack_b)->length > 0)
	{
		set_prices(stack_a, stack_b);
		current = (*stack_b)->stack_head;
		while (current)
		{
			if (current->cheapest == 1)
			{
				parser_moves_combined(stack_a, stack_b, current->position,
					current->target_node->position);
				parser_move_node_to_top_b(stack_b, current->position);
				parser_move_node_to_top_a(stack_a,
					current->target_node->position);
				pa(stack_b, stack_a);
				break ;
			}
			current = current->next;
		}
	}
}

void	sort_lists(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->length > 3)
		pb(stack_a, stack_b);
	tiny_sort_asc(stack_a);
	parser(stack_a, stack_b);
	while ((*stack_a)->min_value != (*stack_a)->stack_head)
	{
		if ((*stack_a)->min_value->position < (*stack_a)->length / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
