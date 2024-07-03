/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:07:10 by anarama           #+#    #+#             */
/*   Updated: 2024/04/08 12:41:24 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	unsigned_c;

	unsigned_c = (unsigned char)c;
	while (*str)
	{
		if ((unsigned char)(*str) == unsigned_c)
			return ((char *)str);
		str++;
	}
	if (unsigned_c == '\0')
		return ((char *)str);
	return (NULL);
}
