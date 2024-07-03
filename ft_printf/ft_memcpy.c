/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:14:32 by anarama           #+#    #+#             */
/*   Updated: 2024/04/19 11:40:45 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*temp_dest;
	char		*temp_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	temp_dest = (char *)dest;
	temp_src = (char *)src;
	while (n--)
		*temp_dest++ = *temp_src++;
	return (dest);
}
