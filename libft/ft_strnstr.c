/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:07:13 by anarama           #+#    #+#             */
/*   Updated: 2024/04/08 20:40:57 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	const char	*temp_haystack;
	const char	*temp_needle;
	size_t		temp_n;

	if (*needle == '\0' || haystack == needle)
		return ((char *)haystack);
	if ((haystack == NULL || needle == NULL) && n == 0)
		return (0);
	while (*haystack && n)
	{
		temp_n = n;
		temp_haystack = haystack;
		temp_needle = needle;
		while (*temp_haystack == *temp_needle && temp_n)
		{
			if (*(temp_needle + 1) == '\0')
				return ((char *)haystack);
			temp_haystack++;
			temp_needle++;
			temp_n--;
		}
		haystack++;
		n--;
	}
	return (NULL);
}
