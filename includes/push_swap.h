/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:34:01 by malee             #+#    #+#             */
/*   Updated: 2024/04/26 04:10:38 by malee            ###   ########.fr       */
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
}					t_stack;

void				print_stacks(t_stack *stack_a, t_stack *stack_b);
void				init_stack(t_stack **stack, char **argv);
void				init_node(t_stack *stack, ssize_t value);
void				error(void);
void				free_nodes(t_stack *stack);

#endif
