/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:07:22 by anarama           #+#    #+#             */
/*   Updated: 2024/04/09 12:13:57 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count_words;

	count_words = 0;
	if (*s != c && *s != '\0')
		count_words++;
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
			count_words++;
		s++;
	}
	return (count_words);
}

static int	helper_len_substr(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static void	free_memory(char **arr)
{
	char	**temp;

	temp = arr;
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(temp);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	**temp_arr;

	if (s == NULL)
		return (NULL);
	arr = (char **)ft_calloc(sizeof(char *), count_words(s, c) + 1);
	temp_arr = arr;
	while (arr && *s)
	{
		while (*s == c && *s)
			s++;
		if (*s != '\0')
		{
			*arr = ft_substr(s, 0, helper_len_substr(s, c));
			if (!*arr)
				return (free_memory(temp_arr), NULL);
			arr++;
		}
		while (*s != c && *s)
			s++;
	}
	return (temp_arr);
}
