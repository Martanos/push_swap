/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:16:16 by malee             #+#    #+#             */
/*   Updated: 2023/09/16 19:13:13 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 	The strdup() function returns a pointer to a new string which is a
	duplicate of the string s.  Memory for the new string is obtained with
	malloc(3), and can  be  freed with free(3). */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	idx;
	char	*dupper;

	dupper = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dupper == NULL)
		return (NULL);
	idx = -1;
	while (s[++idx] != '\0')
		dupper[idx] = s[idx];
	dupper[idx] = '\0';
	return (dupper);
}
