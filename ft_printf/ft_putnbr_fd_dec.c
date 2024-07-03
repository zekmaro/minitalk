/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:20:31 by anarama           #+#    #+#             */
/*   Updated: 2024/04/22 12:13:48 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_dec(int n, int fd, int *counter)
{
	if (n == -2147483648)
    {
        ft_putnbr_fd_dec(-21474, fd, counter);
        ft_putnbr_fd_dec(83648, fd, counter);
        return ;
    }
	if (n < 0)
	{
		ft_putchar_fd('-', fd, counter);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd_dec(n / 10, fd, counter);
	ft_putchar_fd(n % 10 + '0', fd, counter);
}
