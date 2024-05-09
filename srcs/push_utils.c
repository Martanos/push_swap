/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:13:55 by malee             #+#    #+#             */
/*   Updated: 2024/05/08 18:19:26 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_node	*temp;

	update_stack(src);
	if ((*src)->length > 0)
	{
		temp = (*src)->stack_head;
		(*src)->stack_head = temp->next;
		if (temp->next)
			temp->next->prev = NULL;
		else
		{
			(*src)->stack_tail = NULL;
			(*src)->stack_head = NULL;
		}
		temp->next = (*dest)->stack_head;
		if ((*dest)->stack_head)
			(*dest)->stack_head->prev = temp;
		else
			(*dest)->stack_tail = temp;
		(*dest)->stack_head = temp;
	}
	update_stack(dest);
	update_stack(src);
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
