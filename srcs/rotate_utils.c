/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:14:34 by malee             #+#    #+#             */
/*   Updated: 2024/05/08 18:25:22 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_node	*temp;

	if ((*stack)->length > 1)
	{
		temp = (*stack)->stack_head;
		(*stack)->stack_head = temp->next;
		temp->next->prev = NULL;
		temp->next = NULL;
		temp->prev = (*stack)->stack_tail;
		(*stack)->stack_tail->next = temp;
		(*stack)->stack_tail = temp;
	}
	update_stack(stack);
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
