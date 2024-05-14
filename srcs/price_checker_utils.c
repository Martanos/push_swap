/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price_checker_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:41:39 by malee             #+#    #+#             */
/*   Updated: 2024/05/14 20:48:52 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	set_target_node(t_node *current_a, t_stack **stack_b)
// {
// 	t_node	*current_b;

// 	while (current_a)
// 	{
// 		if (current_a->value < (*stack_b)->min_value->value)
// 			current_a->target_node = (*stack_b)->max_value;
// 		else
// 		{
// 			current_a->target_node = (*stack_b)->min_value;
// 			current_b = (*stack_b)->stack_head;
// 			while (current_b)
// 			{
// 				if (current_a->target_node->value < current_b->value
// 					&& current_a->value > current_b->value)
// 					current_a->target_node = current_b;
// 				current_b = current_b->next;
// 			}
// 		}
// 		current_a = current_a->next;
// 	}
// }

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

// static void	set_price(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_node	*stack_a_head;

// 	stack_a_head = (*stack_a)->stack_head;
// 	while (stack_a_head)
// 	{
// 		if (stack_a_head->position <= (*stack_a)->length / 2)
// 			stack_a_head->push_price = stack_a_head->position;
// 		else
// 			stack_a_head->push_price = ((*stack_a)->length
// 					- stack_a_head->position) + 1;
// 		stack_a_head = stack_a_head->next;
// 	}
// 	stack_a_head = (*stack_a)->stack_head;
// 	while (stack_a_head)
// 	{
// 		if (stack_a_head->target_node->position <= (*stack_b)->length / 2)
// 			stack_a_head->push_price += stack_a_head->target_node->position;
// 		else
// 			stack_a_head->push_price += ((*stack_b)->length
// 					- stack_a_head->target_node->position) + 1;
// 		stack_a_head = stack_a_head->next;
// 	}
// }

// static void	set_price(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_node	*stack_b_head;
// 	size_t	diff;

// 	stack_b_head = (*stack_b)->stack_head;
// 	while (stack_b_head)
// 	{
// 		diff = stack_b_head->position - stack_b_head->target_node->position;
// 		if (stack_b_head->position <= ((*stack_b)->length / 2))
// 		{
// 			stack_b_head->push_price = stack_b_head->position;
// 			if (stack_b_head->target_node->position <= ((*stack_a)->length / 2))
// 				stack_b_head->push_price += diff;
// 			else
// 				stack_b_head->push_price += ((*stack_a)->length
// 						- stack_b_head->target_node->position);
// 		}
// 		else if (stack_b_head->position > ((*stack_b)->length / 2))
// 		{
// 			stack_b_head->push_price = ((*stack_b)->length
// 					- stack_b_head->position);
// 			if (stack_b_head->target_node->position <= ((*stack_a)->length / 2))
// 				stack_b_head->push_price += stack_b_head->target_node->position;
// 			else
// 				stack_b_head->push_price += diff;
// 		}
// 		stack_b_head = stack_b_head->next;
// 	}
// }

static void	set_price(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*stack_b_head;

	size_t b_position, a_length, b_length, target_position;
	stack_b_head = (*stack_b)->stack_head;
	while (stack_b_head)
	{
		b_position = stack_b_head->position;
		a_length = (*stack_a)->length;
		b_length = (*stack_b)->length;
		target_position = stack_b_head->target_node->position;
		// Reset push_price
		stack_b_head->push_price = 0;
		// Calculate combined moves (rr and rrr)
		if (b_position <= (b_length / 2) && target_position <= (a_length / 2))
			stack_b_head->push_price = b_position + target_position;
		else if (b_position > (b_length / 2) && target_position > (a_length
				/ 2))
			stack_b_head->push_price = (b_length - b_position) + (a_length
					- target_position);
		// If combined moves are not possible, calculate individual moves
		if (stack_b_head->push_price == 0)
		{
			if (b_position <= (b_length / 2))
			{
				stack_b_head->push_price = b_position;
				if (target_position <= (a_length / 2))
					stack_b_head->push_price += (target_position - b_position);
				else
					stack_b_head->push_price += (a_length - target_position);
			}
			else
			{
				stack_b_head->push_price = (b_length - b_position);
				if (target_position <= (a_length / 2))
					stack_b_head->push_price += target_position;
				else
					stack_b_head->push_price += (target_position - b_position);
			}
		}
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
