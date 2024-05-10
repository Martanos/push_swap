/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:40:06 by malee             #+#    #+#             */
/*   Updated: 2024/05/10 13:29:02 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_printf("Error\n");
	exit(1);
}

static void	check_dup(char *str, char **argv)
{
	while (*argv)
	{
		if (ft_strncmp(str, *argv, ft_strlen(str) + 1) == 0)
			error();
		argv++;
	}
}

static void	check_signs(char *current_argv, int *sign_count)
{
	while (*current_argv)
	{
		if (*current_argv == '-' || *current_argv == '+')
		{
			(*sign_count)++;
			current_argv++;
		}
		if (*sign_count > 1 || !ft_isdigit(*current_argv))
			error();
		current_argv++;
	}
}

static void	check_args(int argc, char **argv)
{
	int	sign_count;

	if (argc < 2)
		error();
	argv++;
	while (*argv)
	{
		sign_count = 0;
		if (ft_atoi(*argv) > INT_MAX || ft_atoi(*argv) < INT_MIN)
			error();
		check_dup(*argv, argv + 1);
		check_signs(*argv, &sign_count);
		argv++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_args(argc, argv);
	init_stack(&stack_a, argv + 1);
	init_stack(&stack_b, NULL);
	if (stack_a->length < 4)
		tiny_sort_asc(&stack_a);
	else if (stack_a->length > 3)
		sort_lists(&stack_a, &stack_b);
	free_nodes(&stack_a);
	free(stack_a);
	free_nodes(&stack_b);
	free(stack_b);
	return (0);
}
