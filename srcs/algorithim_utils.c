/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithim_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:25:41 by malee             #+#    #+#             */
/*   Updated: 2024/05/08 11:37:45 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_lists(t_stack **stack_a, t_stack **stack_b)
{
	ssize_t	pivot;

	pivot = getmedian(stack_a);
	while ((*stack_a)->length > 0 && (*stack_a)->min_value != pivot)
	{
		if ((*stack_a)->min_value_pos <= (*stack_a)->length / 2)
		{
			while ((*stack_a)->stack_head->value != (*stack_a)->min_value)
			{
				rotate(stack_a);
				ft_printf("ra\n");
			}
		}
		else
		{
			while ((*stack_a)->stack_head->value != (*stack_a)->min_value)
			{
				reverse_rotate(stack_a);
				ft_printf("rra\n");
			}
		}
		push(stack_a, stack_b);
		ft_printf("pb\n");
	}
}

void	sort_b(t_stack **stack_b)
{
	update_stack(stack_b);
	if ((*stack_b)->stack_head->value < (*stack_b)->stack_head->next->value)
	{
		swap_head(stack_b);
		ft_printf("sb\n");
	}
	else
	{
		if ((*stack_b)->max_value_pos <= (*stack_b)->length / 2)
		{
			while ((*stack_b)->stack_head->value != (*stack_b)->max_value)
			{
				rotate(stack_b);
				ft_printf("rb\n");
			}
		}
		else
		{
			while ((*stack_b)->stack_head->value != (*stack_b)->max_value)
			{
				reverse_rotate(stack_b);
				ft_printf("rrb\n");
			}
		}
	}
}

void	sort_a(t_stack **stack_a)
{
	update_stack(stack_a);
	if ((*stack_a)->stack_head->value > (*stack_a)->stack_head->next->value)
	{
		swap_head(stack_a);
		ft_printf("sa\n");
	}
	else
	{
		if ((*stack_a)->min_value_pos <= (*stack_a)->length / 2)
		{
			while ((*stack_a)->stack_head->value != (*stack_a)->min_value)
			{
				rotate(stack_a);
				ft_printf("ra\n");
			}
		}
		else
		{
			while ((*stack_a)->stack_head->value != (*stack_a)->min_value)
			{
				reverse_rotate(stack_a);
				ft_printf("rra\n");
			}
		}
	}
}

void	sort_lists(t_stack **stack_a, t_stack **stack_b)
{
	// print_stacks(*stack_a, *stack_b);
	split_lists(stack_a, stack_b);
	// print_stacks(*stack_a, *stack_b);
	while (!is_sorted_ascended(*stack_a))
		sort_a(stack_a);
	while (!is_sorted_descended(*stack_b))
		sort_b(stack_b);
	while ((*stack_b)->stack_head != NULL)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
	// print_stacks(*stack_a, *stack_b);
}
