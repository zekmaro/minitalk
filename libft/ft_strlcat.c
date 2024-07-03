/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:37:45 by anarama           #+#    #+#             */
/*   Updated: 2024/04/09 12:00:40 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	temp;

	if ((dest == NULL || src == NULL) && size == 0)
		return (0);
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (len_dest >= size)
		return (size + len_src);
	temp = size - len_dest - 1;
	dest += len_dest;
	while (*src && temp-- && size != 0)
		*dest++ = *src++;
	if (size != 0)
		*dest = '\0';
	return (len_dest + len_src);
}
