/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:01:33 by anarama           #+#    #+#             */
/*   Updated: 2024/04/07 14:13:37 by anarama          ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len_s1;
	unsigned int	len_s2;
	char			*cat_result;
	char			*temp_cat_result;

	len_s1 = helper_strlen(s1);
	len_s2 = helper_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	cat_result = (char *)malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (!cat_result)
		return (NULL);
	temp_cat_result = cat_result;
	while (*s1)
		*cat_result++ = *s1++;
	while (*s2)
		*cat_result++ = *s2++;
	*cat_result = '\0';
	return (temp_cat_result);
}
