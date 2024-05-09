/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price_checker_desc_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:11:08 by malee             #+#    #+#             */
/*   Updated: 2024/05/08 21:22:28 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_node_desc(t_node *stack_a_head, t_node *stack_b_head,
		t_stack **stack_a)
{
	t_node	*target_node;
	size_t	best_match_index;

	while (stack_b_head)
	{
		best_match_index = 0;
		target_node = NULL;
		while (stack_a_head)
		{
			if (stack_a_head->value < stack_b_head->value
				&& stack_a_head->value > best_match_index)
			{
				best_match_index = stack_a_head->value;
				target_node = stack_a_head;
			}
			stack_a_head = stack_a_head->next;
		}
		if (target_node == NULL)
			stack_b_head->target_node_desc = (*stack_a)->max_value;
		else
			stack_b_head->target_node_desc = target_node;
		stack_b_head = stack_b_head->next;
	}
}

void	set_price_desc(t_node *stack_a_head, t_node *stack_b_head,
		t_stack **stack_a, t_stack **stack_b)
{
	ssize_t	median_pos_a;
	ssize_t	median_pos_b;

	median_pos_a = (*stack_a)->length / 2;
	median_pos_b = (*stack_b)->length / 2;
	while (stack_b_head)
	{
		stack_b_head->push_price_desc = stack_b_head->position;
		if (stack_b_head->position > median_pos_b)
			stack_b_head->push_price_desc = (*stack_b)->length
				- stack_b_head->position;
		if (stack_b_head->target_node_desc->position < median_pos_a)
			stack_b_head->push_price_desc
				+= stack_b_head->target_node_desc->position;
		else
			stack_b_head->push_price_desc = (*stack_a)->length
				- stack_b_head->target_node_desc->position;
		stack_b_head = stack_b_head->next;
	}
}

void	set_cheapest_desc_b(t_node *stack_b_head, t_stack *stack_b)
{
	ssize_t	best_match_value;
	t_node	*best_match_node;

	best_match_value = LONG_MAX;
	best_match_node = NULL;
	while (stack_b_head)
	{
		if (stack_b_head->push_price_desc < best_match_value)
		{
			best_match_value = stack_b_head->push_price_desc;
			best_match_node = stack_b_head;
		}
		stack_b_head = stack_b_head->next;
	}
	if (best_match_node != NULL)
		best_match_node->cheapest_desc = 1;
}
