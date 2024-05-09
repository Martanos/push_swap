/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price_checker_asc_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:41:39 by malee             #+#    #+#             */
/*   Updated: 2024/05/08 20:40:21 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_node_asc(t_node *stack_a_head, t_node *stack_b_head,
		t_stack **stack_a)
{
	t_node	*target_node;
	size_t	best_match_index;

	while (stack_b_head)
	{
		best_match_index = LONG_MAX;
		while (stack_a_head)
		{
			if (stack_a_head->value > stack_b_head->value
				&& stack_a_head->value < best_match_index)
			{
				best_match_index = stack_a_head->value;
				target_node = stack_a_head;
			}
			stack_a_head = stack_a_head->next;
		}
		if (LONG_MAX == best_match_index)
			stack_b_head->target_node_asc = (*stack_a)->min_value;
		else
			stack_b_head->target_node_asc = target_node;
		stack_b_head = stack_b_head->next;
	}
}

void	set_price_asc(t_node *stack_a_head, t_node *stack_b_head,
		t_stack **stack_a, t_stack **stack_b)
{
	ssize_t	median_pos;

	median_pos = (*stack_b)->length / 2;
	while (stack_b_head)
	{
		stack_b_head->push_price_asc = stack_b_head->position;
		if (stack_b_head->position < median_pos)
			stack_b_head->push_price_asc = (*stack_a)->length
				- stack_b_head->position;
		if (stack_b_head->target_node_asc->position < median_pos)
			stack_b_head->push_price_asc
				+= stack_b_head->target_node_asc->position;
		else
			stack_b_head->push_price_asc = (*stack_a)->length
				- stack_b_head->target_node_asc->position;
		stack_b_head = stack_b_head->next;
	}
}

void	set_cheapest_asc(t_node *stack_b_head, t_stack **stack_b)
{
	ssize_t	best_match_value;
	t_node	*best_match_node;

	if (!stack_b_head)
		return ;
	best_match_value = LONG_MAX;
	while (stack_b_head)
	{
		if (stack_b_head->push_price_asc < best_match_value)
		{
			best_match_value = stack_b_head->push_price_asc;
			best_match_node = stack_b_head;
		}
		stack_b_head = stack_b_head->next;
	}
	best_match_node->cheapest_asc = 1;
}

void	set_prices(t_stack **stack_a, t_stack **stack_b)
{
	set_target_node_asc((*stack_a)->stack_head, (*stack_b)->stack_head,
		stack_a);
	set_price_asc((*stack_a)->stack_head, (*stack_b)->stack_head, stack_a,
		stack_b);
	set_cheapest_asc((*stack_b)->stack_head, stack_b);
}
