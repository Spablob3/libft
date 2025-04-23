/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:47:32 by joapedro          #+#    #+#             */
/*   Updated: 2025/04/22 15:45:04 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
		{
			i++;
		}
		if (s[i])
		{
			count++;
		}
		while (s[i] != c && s[i])
		{
			i++;
		}
	}
	return (count);
}

static char	*word_dup(char *s, char c)
{
	char	*str_dup;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	str_dup = ft_calloc((i + 1), sizeof(char));
	if (!str_dup)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str_dup[i] = s[i];
		i++;
	}
	return (str_dup);
}

static char	**free_memory(char **str, int word)
{
	int	i;

	i = 0;
	while (i < word)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

static char	**fill_words(char **str, const char *s, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (word < word_count(s, c))
	{
		while (s[i] == c && s[i])
		{
			i++;
		}
		if (s[i] && s[i] != c)
		{
			str[word] = word_dup((char *)&s[i], c);
			if (!str[word])
				return (free_memory(str, word));
		}
		while (s[i] != c && s[i])
			i++;
		word++;
	}
	str[word] = 0;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**str;

	if (!s)
	{
		return (NULL);
	}
	str = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!str)
	{
		return (NULL);
	}
	return (fill_words(str, s, c));
}
/*
#include <stdio.h>
int	main()
{
	char str[] = "__eu_estou__aqui__";
	char	c = '_';
	char	**array;
	int	i = 0;

	array = ft_split(str, c);
	while (array[i])
	{
		printf("%s\n", array[i]);
		free(array[i]);
		i++;
	}
	free(array);
}
*/