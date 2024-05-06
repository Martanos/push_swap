/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:34:01 by malee             #+#    #+#             */
/*   Updated: 2024/05/06 20:57:31 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
	ssize_t			value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	size_t			length;
	t_node			*stack_head;
	t_node			*stack_tail;
	int				is_sorted;
	ssize_t			min_value;
	ssize_t			max_value;
}					t_stack;

typedef struct s_move_handlers
{
	char			*specifier;
	void			(**handlers)(va_list *args);
}					t_move_handlers;

void				print_stacks(t_stack *stack_a, t_stack *stack_b);
void				init_stack(t_stack **stack, char **argv);
void				init_node(t_stack *stack, ssize_t value);
void				error(void);
void				free_nodes(t_stack *stack);
void				swap_head(t_stack *stack);
void				push(t_stack *src, t_stack *dest);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);
int					is_sorted_ascended(t_stack *stack);
int					is_sorted_descended(t_stack *stack);
void				sort_lists(t_stack **stack_a, t_stack **stack_b);

#endif
