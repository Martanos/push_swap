/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:34:01 by malee             #+#    #+#             */
/*   Updated: 2024/05/08 20:43:12 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
	ssize_t			position;
	ssize_t			value;
	int				cheapest_asc;
	int				cheapest_desc;
	ssize_t			push_price_asc;
	ssize_t			push_price_desc;
	struct s_node	*target_node_asc;
	struct s_node	*target_node_desc;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	ssize_t			length;
	t_node			*stack_head;
	t_node			*stack_tail;
	int				is_sorted_asc;
	int				is_sorted_desc;
	t_node			*min_value;
	t_node			*max_value;
}					t_stack;

// General Utils
void				error(void);
// Node Utils
void				init_node(t_stack **stack, ssize_t value);
void				free_nodes(t_stack **stack);
void				set_prices(t_stack **stack_a, t_stack **stack_b);
// Stack utils
void				init_stack(t_stack **stack, char **argv);
int					is_sorted_ascended(t_stack *stack);
int					is_sorted_descended(t_stack *stack);
void				sort_lists(t_stack **stack_a, t_stack **stack_b);
t_node				*find_largest_node(t_stack **stack);
t_node				*find_smallest_node(t_stack **stack);
void				update_stack(t_stack **stack);
// Move utils
void				pa(t_stack **stack_b, t_stack **stack_a);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
t_node				*get_median(t_stack *stack);

#endif
