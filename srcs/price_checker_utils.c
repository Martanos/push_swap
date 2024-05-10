/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price_checker_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:41:39 by malee             #+#    #+#             */
/*   Updated: 2024/05/10 13:49:36 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_node(t_node *stack_a_head, t_node *stack_b_head,
		t_stack **stack_b)
{
	t_node	*target_node;
	ssize_t	best_match_index;

	while (stack_a_head)
	{
		target_node = (*stack_b)->min_value;
		best_match_index = LONG_MIN;
		while (stack_b_head)
		{
			if (stack_b_head->value > stack_a_head->value
				&& best_match_index < stack_b_head->value)
			{
				best_match_index = stack_b_head->value;
				target_node = stack_b_head;
			}
			stack_b_head = stack_b_head->next;
		}
		if (best_match_index == LONG_MIN)
			stack_a_head->target_node = (*stack_b)->min_value;
		else
			stack_a_head->target_node = target_node;
		stack_a_head = stack_a_head->next;
	}
}

static void	set_price(t_node *stack_a_head,
		t_stack **stack_a, t_stack **stack_b)
{
	while (stack_a_head)
	{
		stack_a_head->push_price = stack_a_head->position;
		if (stack_a_head->position > (*stack_a)->length / 2)
			stack_a_head->push_price = (*stack_a)->length
				- stack_a_head->position;
		if (stack_a_head->target_node->position < (*stack_b)->length / 2)
			stack_a_head->push_price += stack_a_head->target_node->position;
		else
			stack_a_head->push_price += (*stack_b)->length
				- stack_a_head->target_node->position;
		stack_a_head = stack_a_head->next;
	}
}

static void	set_cheapest(t_node *stack_a_head)
{
	ssize_t	best_match_value;
	t_node	*best_match_node;

	if (!stack_a_head)
		return ;
	best_match_value = LONG_MAX;
	best_match_node = stack_a_head;
	while (stack_a_head)
	{
		if (stack_a_head->push_price < best_match_value)
		{
			best_match_value = stack_a_head->push_price;
			best_match_node = stack_a_head;
		}
		stack_a_head = stack_a_head->next;
	}
	best_match_node->cheapest = 1;
}

void	set_prices(t_stack **stack_a, t_stack **stack_b)
{
	set_target_node((*stack_a)->stack_head, (*stack_b)->stack_head, stack_b);
	set_price((*stack_a)->stack_head, stack_a, stack_b);
	set_cheapest((*stack_a)->stack_head);
}
