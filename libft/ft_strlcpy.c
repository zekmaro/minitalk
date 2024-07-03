/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:19:07 by anarama           #+#    #+#             */
/*   Updated: 2024/04/08 20:29:57 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len_src;

	len_src = 0;
	while (*src)
	{
		if (len_src < size - 1 && size != 0)
			*dest++ = *src;
		src++;
		len_src++;
	}
	if (size != 0)
		*dest = '\0';
	return (len_src);
}
