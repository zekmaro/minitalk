/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:36:19 by anarama           #+#    #+#             */
/*   Updated: 2024/04/08 20:24:27 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char		*dest;
	const char	*src;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	dest = (char *)str1;
	src = (char *)str2;
	if (dest <= src)
	{
		while (n--)
			*dest++ = *src++;
	}
	else
	{
		src += n - 1;
		dest += n - 1;
		while (n--)
			*dest-- = *src--;
	}
	return (str1);
}
