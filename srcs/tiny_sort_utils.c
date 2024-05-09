/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:39:12 by malee             #+#    #+#             */
/*   Updated: 2024/05/08 22:02:11 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort_asc(t_stack **stack)
{
	t_node	*highest_node;

	highest_node = (*stack)->min_value;
	if ((*stack)->stack_head == highest_node)
		ra(stack);
	else if ((*stack)->stack_head->next == highest_node)
		rra(stack);
	if ((*stack)->stack_head->value > (*stack)->stack_head->next->value)
		sa(stack);
}

void	tiny_sort_desc(t_stack **stack)
{
	t_node	*lowest_node;

	lowest_node = (*stack)->max_value;
	if ((*stack)->stack_head == lowest_node)
		ra(stack);
	else if ((*stack)->stack_head->next == lowest_node)
		rra(stack);
	if ((*stack)->stack_head->value < (*stack)->stack_head->next->value)
		sa(stack);
}
