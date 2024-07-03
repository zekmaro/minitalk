/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:24:07 by anarama           #+#    #+#             */
/*   Updated: 2024/05/23 21:25:29 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_ptr(ssize_t n, int fd, int *counter, int flag)
{
	if (n == -1)
	{
		write(1, "0xffffffff", 10);
		return ;
	}
	if (flag == 1)
	{
		if (n == 0)
		{
			write(1, "(nil)", 5);
			*counter += 5;
			return ;
		}
		write(1, "0x", 2);
		*counter += 2;
	}
	if (n >= 16)
		ft_putnbr_fd_ptr(n / 16, fd, counter, 0);
	if (n % 16 >= 10)
		ft_putchar_fd_prf((n % 16) - 10 + 'a', fd, counter);
	else
		ft_putchar_fd_prf((n % 16) + '0', fd, counter);
}
