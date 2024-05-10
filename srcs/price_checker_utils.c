/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price_checker_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:41:39 by malee             #+#    #+#             */
/*   Updated: 2024/05/11 02:17:17 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_node(t_node *current_a, t_stack **stack_b)
{
	t_node	*current_b;

	while (current_a)
	{
		if (current_a->value < (*stack_b)->min_value->value)
			current_a->target_node = (*stack_b)->max_value;
		else
		{
			current_a->target_node = (*stack_b)->min_value;
			current_b = (*stack_b)->stack_head;
			while (current_b)
			{
				if (current_b->value >= current_a->target_node->value
					&& current_a->value >= current_b->value)
					current_a->target_node = current_b;
				current_b = current_b->next;
			}
		}
		current_a = current_a->next;
	}
}

static void	set_price(t_node *stack_a_head, t_stack **stack_a,
		t_stack **stack_b)
{
	while (stack_a_head)
	{
		if (stack_a_head->position >= (*stack_a)->length / 2)
			stack_a_head->push_price = (*stack_a)->length
				- stack_a_head->position;
		else
			stack_a_head->push_price = ((*stack_a)->length / 2)
				- stack_a_head->position;
		if (stack_a_head->target_node->position >= (*stack_b)->length / 2)
			stack_a_head->push_price += (*stack_b)->length
				- stack_a_head->target_node->position;
		else
			stack_a_head->push_price += ((*stack_b)->length / 2)
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
	best_match_value = stack_a_head->push_price;
	best_match_node = stack_a_head;
	while (stack_a_head)
	{
		stack_a_head->cheapest = 0;
		if (stack_a_head->push_price <= best_match_value)
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
	set_target_node((*stack_a)->stack_head, stack_b);
	set_price((*stack_a)->stack_head, stack_a, stack_b);
	set_cheapest((*stack_a)->stack_head);
}
