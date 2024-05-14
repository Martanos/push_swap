/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price_checker_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:41:39 by malee             #+#    #+#             */
/*   Updated: 2024/05/15 00:41:00 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_node(t_node *current_b, t_stack **stack_a)
{
	t_node	*current_a;

	while (current_b)
	{
		current_b->target_node = (*stack_a)->max_value;
		current_a = (*stack_a)->stack_head;
		while (current_a)
		{
			if (current_a->value > current_b->value
				&& current_a->value < current_b->target_node->value)
				current_b->target_node = current_a;
			else if (current_b->value > (*stack_a)->max_value->value)
				current_b->target_node = (*stack_a)->min_value;
			current_a = current_a->next;
		}
		current_b = current_b->next;
	}
}

static void	set_price_helper(t_node *stack_b_head, size_t a_length,
		size_t b_length)
{
	size_t	b_position;
	size_t	target_pos;

	b_position = stack_b_head->position;
	target_pos = stack_b_head->target_node->position;
	if (b_position <= (b_length / 2))
	{
		stack_b_head->push_price = b_position;
		if (target_pos <= (a_length / 2))
			stack_b_head->push_price += (target_pos - b_position);
		else
			stack_b_head->push_price += (a_length - target_pos);
	}
	else
	{
		stack_b_head->push_price = (b_length - b_position);
		if (target_pos <= (a_length / 2))
			stack_b_head->push_price += target_pos;
		else
			stack_b_head->push_price += (target_pos - b_position);
	}
}

static void	set_price(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*stack_b_head;
	size_t	b_position;
	size_t	a_length;
	size_t	b_length;
	size_t	target_pos;

	stack_b_head = (*stack_b)->stack_head;
	while (stack_b_head)
	{
		b_position = stack_b_head->position;
		a_length = (*stack_a)->length;
		b_length = (*stack_b)->length;
		target_pos = stack_b_head->target_node->position;
		stack_b_head->push_price = 0;
		if (b_position <= (b_length / 2) && target_pos <= (a_length / 2))
			stack_b_head->push_price = stack_b_head->position
				+ stack_b_head->target_node->position;
		else if (b_position > (b_length / 2) && target_pos > (a_length / 2))
			stack_b_head->push_price = (b_length - b_position) + (a_length
					- target_pos);
		else if (stack_b_head->push_price == 0)
			set_price_helper(stack_b_head, a_length, b_length);
		stack_b_head = stack_b_head->next;
	}
}

static void	set_cheapest(t_node *stack_head)
{
	ssize_t	best_match_value;
	t_node	*best_match_node;

	best_match_value = stack_head->push_price;
	best_match_node = stack_head;
	while (stack_head)
	{
		stack_head->cheapest = 0;
		if (stack_head->push_price <= best_match_value)
		{
			best_match_value = stack_head->push_price;
			best_match_node = stack_head;
		}
		stack_head = stack_head->next;
	}
	best_match_node->cheapest = 1;
}

void	set_prices(t_stack **stack_a, t_stack **stack_b)
{
	set_target_node((*stack_b)->stack_head, stack_a);
	set_price(stack_a, stack_b);
	set_cheapest((*stack_b)->stack_head);
}
