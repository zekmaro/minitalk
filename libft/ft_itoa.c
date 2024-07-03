/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 10:58:22 by anarama           #+#    #+#             */
/*   Updated: 2024/04/08 17:09:26 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_array(char *str, int n)
{
	if (n >= 10)
		fill_array(str - 1, n / 10);
	*str = (n % 10) + '0';
}

static	int	get_len_number(int n)
{
	int	len_n;

	len_n = 0;
	if (n == 0)
		len_n = 1;
	while (n)
	{
		len_n += 1;
		n /= 10;
	}
	return (len_n);
}

static	char	*handle_int_min(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 11 + 1);
	if (!str)
		return (NULL);
	str = ft_memcpy(str, "-2147483648", 11);
	*(str + 11) = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len_n;
	char	*temp_str;
	int		shift_for_minus;

	shift_for_minus = 0;
	if (n == -2147483648)
		return (handle_int_min());
	if (n < 0)
		shift_for_minus += 1;
	len_n = get_len_number(n);
	str = (char *)malloc(sizeof(char) * len_n + shift_for_minus + 1);
	if (!str)
		return (NULL);
	temp_str = str;
	if (n < 0)
	{
		*str++ = '-';
		n *= -1;
	}
	fill_array(str + (len_n - 1), n);
	*(str + len_n) = '\0';
	return (temp_str);
}
