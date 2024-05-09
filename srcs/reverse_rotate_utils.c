/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:14:31 by malee             #+#    #+#             */
/*   Updated: 2024/05/08 18:27:02 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_node	*temp;

	if ((*stack)->length > 1)
	{
		temp = (*stack)->stack_tail;
		(*stack)->stack_tail = temp->prev;
		temp->prev->next = NULL;
		temp->prev = NULL;
		temp->next = (*stack)->stack_head;
		(*stack)->stack_head->prev = temp;
		(*stack)->stack_head = temp;
	}
	update_stack(stack);
}
void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
