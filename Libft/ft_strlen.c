/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:41:20 by malee             #+#    #+#             */
/*   Updated: 2023/09/14 19:29:27 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks amount of char characters in a char array */

int	ft_strlen(char *input)
{
	int	idx;

	idx = 0;
	while (*input)
	{
		idx++;
		input++;
	}
	return (idx);
}
