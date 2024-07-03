/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:58:11 by anarama           #+#    #+#             */
/*   Updated: 2024/05/23 14:13:17 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*skip_spaces(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	int			num;
	const char	*temp_str;

	num = 0;
	temp_str = skip_spaces(str);
	if (*temp_str == '-' || *temp_str == '+')
		temp_str++;
	while ((*temp_str - '0') >= 0 && (*temp_str - '0') <= 9)
	{
		num *= 10;
		num += *temp_str - '0';
		temp_str++;
	}
	if (*skip_spaces(str) == '-')
		num *= -1;
	return (num);
}
