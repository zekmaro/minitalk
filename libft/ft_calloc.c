/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:24:35 by anarama           #+#    #+#             */
/*   Updated: 2024/04/15 11:57:58 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*mem;
	size_t	total_size;

	total_size = size * num;
	if (num == 0 || size == 0)
		total_size = 0;
	else if (SIZE_MAX / num < size)
		return (NULL);
	mem = (char *)malloc(total_size);
	if (!mem)
		return (NULL);
	return (ft_memset(mem, 0, total_size));
}
