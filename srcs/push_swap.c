/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:40:06 by malee             #+#    #+#             */
/*   Updated: 2024/05/15 23:31:35 by malee            ###   ########.fr       */
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

static void	check_args(char **argv)
{
	int	sign_count;

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

	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		check_args(argv);
		stack_a = NULL;
		stack_b = NULL;
		init_stack(&stack_b, NULL);
		init_stack(&stack_a, argv);
		if (!(is_sorted_ascended(stack_a)))
			sort_lists(&stack_a, &stack_b);
		free_stacks(&stack_a, &stack_b);
	}
	return (0);
}
