/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:27:58 by malee             #+#    #+#             */
/*   Updated: 2024/05/26 13:27:59 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_args(char **argv, char **args_to_free)
{
	if (args_to_free)
	{
		while (*args_to_free)
		{
			free(*args_to_free);
			args_to_free++;
		}
		free(argv);
	}
}

static int	check_dup(char **argv, int len)
{
	char	*str;

	str = NULL;
	if (len == 1)
		return (1);
	else
	{
		str = *argv;
		argv++;
	}
	while (*argv)
	{
		if (ft_strncmp(str, *argv, ft_strlen(str) + 1) == 0)
			return (0);
		argv++;
	}
	return (1);
}

static int	check_signs(char *current_argv)
{
	int	sign_count;

	sign_count = 0;
	while (*current_argv)
	{
		if (*current_argv == '-' || *current_argv == '+')
		{
			sign_count++;
			current_argv++;
		}
		if (sign_count > 1 || !ft_isdigit(*current_argv))
			return (0);
		current_argv++;
	}
	return (1);
}

static void	check_args(char **argv, char **args_to_free)
{
	ssize_t	len;
	int		error;

	len = -1;
	error = 1;
	while (argv[++len])
		;
	while (*argv)
	{
		if (ft_atoi(*argv) > INT_MAX || ft_atoi(*argv) < INT_MIN)
			error = 0;
		if (!check_dup(argv, len))
			error = 0;
		if (!check_signs(*argv))
			error = 0;
		argv++;
	}
	if (!error)
	{
		free_args(argv, args_to_free);
		ft_printf("Error\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args_to_free;

	args_to_free = NULL;
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
		{
			argv = ft_split(*argv, ' ');
			args_to_free = argv;
		}
		check_args(argv, args_to_free);
		stack_a = NULL;
		stack_b = NULL;
		init_stack(&stack_b, NULL);
		init_stack(&stack_a, argv);
		if (!(is_sorted_ascended(stack_a)))
			sort_lists(&stack_a, &stack_b);
		free_stacks(&stack_a, &stack_b);
		free_args(argv, args_to_free);
	}
	return (0);
}
