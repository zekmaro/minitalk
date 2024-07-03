/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:22:05 by anarama           #+#    #+#             */
/*   Updated: 2024/04/15 11:40:26 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_empty_str(void)
{
	char	*str;

	str = (char *)malloc(1);
	if (str)
		*str = '\0';
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len_s;
	char			*new_s;
	char			*temp_new_s;
	unsigned int	index;

	if (s == NULL || f == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s == 0)
		return (get_empty_str());
	new_s = (char *)malloc(sizeof(char) * len_s + 1);
	if (!new_s)
		return (new_s);
	temp_new_s = new_s;
	index = 0;
	while (index < len_s)
	{
		*new_s++ = f(index, *s);
		index++;
		s++;
	}
	*new_s = '\0';
	return (temp_new_s);
}
