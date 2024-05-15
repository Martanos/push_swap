/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:41:17 by malee             #+#    #+#             */
/*   Updated: 2024/05/16 00:12:25 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Allocates (with malloc(3)) and returns an array
	of strings obtained by splitting ’s’ using the
	character ’c’ as a delimiter. The array must end
	with a NULL pointer. */

#include "libft.h"

static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (NULL);
}

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_putword(char const *s, int i, int word_len)
{
	char	*word;
	int		j;

	j = 0;
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **s2, int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = ft_putword(s, i, word_len);
		if (!s2[word])
			return (free_array(s2, word));
		word_len = 0;
		word++;
	}
	word++;
	s2[word] = NULL;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char			**s2;
	unsigned int	num_words;

	if (!s)
		return (NULL);
	num_words = ft_count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
		return (NULL);
	if (num_words == 1)
	{
		s2[0] = (char *)s;
		return (s2);
	}
	s2 = ft_split_words(s, c, s2, num_words);
	return (s2);
}
