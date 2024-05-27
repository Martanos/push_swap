/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:27:58 by malee             #+#    #+#             */
/*   Updated: 2024/05/28 03:21:23 by malee            ###   ########.fr       */
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

static int	check_dup(char **argv, char **args_to_free)
{
	char	*str1;
	char	**str2;
	ssize_t	len;

	str1 = *argv;
	str2 = argv + 1;
	len = -1;
	while (argv[++len])
		;
	if (len == 1)
		return (0);
	while (*str2)
	{
		if (ft_atoi(str1) == ft_atoi(*str2))
		{
			free_args(argv, args_to_free);
			exit(write(STDERR_FILENO, "Error\n", 6) > 0);
		}
		str2++;
	}
	return (0);
}

static int	check_signs(char *current_argv)
{
	int	sign_count;
	int	len;

	sign_count = 0;
	len = 0;
	while (current_argv[len])
	{
		if ((current_argv[len] == '-' || current_argv[len] == '+') && len == 0)
		{
			sign_count++;
			len++;
			if (current_argv[len - 1] == '-' && current_argv[len] == '0')
				return (1);
		}
		if (sign_count > 1 || !ft_isdigit(current_argv[len]))
			return (1);
		len++;
	}
	return (0);
}

static void	check_args(char **argv, char **args_to_free)
{
	int		error;
	char	**temp;

	error = 0;
	temp = argv;
	error += (*temp == NULL);
	while (*temp)
	{
		error += check_signs(*temp);
		error += (ft_atoi(*temp) > INT_MAX || ft_atoi(*temp) < INT_MIN);
		temp++;
	}
	if (error)
	{
		free_args(argv, args_to_free);
		exit(write(STDERR_FILENO, "Error\n", 6) > 0);
	}
	temp = argv;
	while (*temp)
	{
		check_dup(temp, args_to_free);
		temp++;
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
		free_args(argv, args_to_free);
		if (!(is_sorted_ascended(stack_a)))
			sort_lists(&stack_a, &stack_b);
		free_stacks(&stack_a, &stack_b);
	}
	return (0);
}
