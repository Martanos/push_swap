/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:40:06 by malee             #+#    #+#             */
/*   Updated: 2024/04/19 03:03:26 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error(void)
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
		while (**argv)
		{
			if (**argv == '-' || **argv == '+')
			{
				sign_count++;
				(*argv)++;
			}
			if (sign_count > 1 || !ft_isdigit(**argv))
				error();
			(*argv)++;
		}
		argv++;
	}
}

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	return (0);
}

