/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:52:40 by malee             #+#    #+#             */
/*   Updated: 2024/05/08 19:37:45 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_median(t_stack *stack)
{
	ssize_t	min_diff;
	ssize_t	diff;
	t_node	*pos_address;
	t_node	*current;

	pos_address == NULL;
	min_diff = LONG_MIN;
	current = stack->stack_head;
	while (!stack->stack_head->next)
	{
		diff = current->value - stack->min_value->value;
		diff = current->value - stack->max_value->value;
		if (diff < min_diff)
		{
			min_diff = diff;
			pos_address = current;
		}
		current = current->next;
	}
	return (pos_address);
}
