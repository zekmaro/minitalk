/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:49:48 by anarama           #+#    #+#             */
/*   Updated: 2024/04/09 12:10:52 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_start(char const *s1, char const *set)
{
	char	*temp_set;
	int		in_set;

	while (*s1)
	{
		in_set = 0;
		temp_set = (char *)set;
		while (*temp_set)
		{
			if (*temp_set == *s1)
				in_set = 1;
			temp_set++;
		}
		if (!in_set)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}

static char	*get_end(char const *s1, char const *set, size_t len_s1)
{
	char	*temp_set;
	int		in_set;

	len_s1--;
	while (len_s1)
	{
		in_set = 0;
		temp_set = (char *)set;
		while (*temp_set)
		{
			if (*temp_set == *(s1 + len_s1))
				in_set = 1;
			temp_set++;
		}
		if (!in_set)
			return ((char *)(s1 + len_s1));
		len_s1--;
	}
	return (NULL);
}

static char	*get_empty_str(void)
{
	char	*str;

	str = (char *)malloc(1);
	if (str)
		*str = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed_s1;
	unsigned int	len_s1;
	char			*start;
	char			*end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*s1 == '\0')
		return (get_empty_str());
	len_s1 = ft_strlen(s1);
	start = get_start(s1, set);
	end = get_end(s1, set, len_s1);
	if (start == NULL || end == NULL)
		return (get_empty_str());
	trimmed_s1 = (char *)malloc(sizeof(char) * (end - start + 1) + 1);
	if (!trimmed_s1)
		return (NULL);
	trimmed_s1 = ft_memcpy(trimmed_s1, start, end - start + 1);
	*(trimmed_s1 + (end - start + 1)) = '\0';
	return (trimmed_s1);
}
