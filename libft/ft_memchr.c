/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:49:58 by anarama           #+#    #+#             */
/*   Updated: 2024/04/07 19:26:47 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	unsigned_c;
	unsigned char	*unsigned_str;

	unsigned_str = (unsigned char *)str;
	unsigned_c = (unsigned char)c;
	if (n == 0)
		return (NULL);
	while (n--)
	{
		if (*unsigned_str == unsigned_c)
			return ((void *)unsigned_str);
		unsigned_str++;
	}
	return (NULL);
}
