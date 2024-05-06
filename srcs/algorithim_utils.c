/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithim_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:25:41 by malee             #+#    #+#             */
/*   Updated: 2024/05/06 20:57:48 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getmiddlevalue(t_stack *stack)
{
	t_node	*slow;
	t_node	*fast;

	slow = stack->stack_head;
	fast = stack->stack_head;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return (slow->value);
}

void	split_lists(t_stack **stack_a, t_stack **stack_b)
{
	ssize_t	pivot;
	ssize_t	itr;

	pivot = getmiddlevalue(*stack_a);
	itr = -1;
	while (itr++ <= (*stack_a)->length)
	{
		if ((*stack_a)->stack_head->value <= pivot)
		{
			push(stack_a, stack_b);
			ft_printf("pb\n");
		}
		else
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}
	}
}

void	sort_a_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (!is_sorted_descended(*stack_b)
		&& (*stack_b)->stack_head->value < (*stack_b)->stack_head->next->value)
	{
		swap_head(stack_a);
		swap_head(stack_b);
		ft_printf("ss\n");
	}
	else
	{
		swap_head(stack_a);
		ft_printf("sa\n");
	}
}

void	sort_a(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->stack_head->value > (*stack_a)->stack_head->next->value)
		sort_a_swap(stack_a, stack_b);
	else
	{
		if (!is_sorted_descended(*stack_b))
		{
			rotate(stack_a);
			rotate(stack_b);
			ft_printf("rr\n");
		}
		else
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}
	}
}

void	sort_lists(t_stack **stack_a, t_stack **stack_b)
{
	split_lists(stack_a, stack_b);
	while (!is_sorted_ascended(*stack_a) || !is_sorted_descended(*stack_b))
	{
		if (!is_sorted_ascended(*stack_a))
			sort_a(stack_a, stack_b);
		else if ((*stack_b)->stack_head->value < (*stack_b)->stack_head->next->value)
		{
			sb(stack_b);
			ft_printf("sb\n");
		}
		else
		{
			rb(stack_b);
			ft_printf("rb\n");
		}
	}
	while (!isEmpty(*stack_b))
	{
		pa(stack_b, stack_a);
		ft_printf("pa\n");
	}
}
