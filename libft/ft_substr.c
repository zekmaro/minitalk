/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:05:20 by anarama           #+#    #+#             */
/*   Updated: 2024/04/09 12:13:02 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	helper_strlen(char const *s)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

static char	*get_empty_str(void)
{
	char	*str;

	str = (char *)malloc(1);
	if (str)
		*str = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*temp_substr;
	size_t	len_s;

	len_s = helper_strlen(s);
	if (s == NULL || start >= len_s || len == 0)
		return (get_empty_str());
	if (len + start > len_s)
		len = len_s - start;
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	temp_substr = substr;
	s += start;
	while (len && *s)
	{
		*substr++ = *s++;
		len--;
	}
	*substr = '\0';
	return (temp_substr);
}
