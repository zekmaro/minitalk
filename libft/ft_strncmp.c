/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:41:51 by anarama           #+#    #+#             */
/*   Updated: 2024/04/07 14:29:14 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	const unsigned char	*temp_str1;
	const unsigned char	*temp_str2;

	temp_str1 = (const unsigned char *)str1;
	temp_str2 = (const unsigned char *)str2;
	if (n == 0)
		return (0);
	while (*temp_str1 == *temp_str2 && n-- > 1 && *temp_str1 && temp_str2)
	{
		temp_str1++;
		temp_str2++;
	}
	return (*temp_str1 - *temp_str2);
}
