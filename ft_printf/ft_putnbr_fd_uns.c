/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_uns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:05:01 by anarama           #+#    #+#             */
/*   Updated: 2024/05/23 21:25:32 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_uns(size_t n, int fd, int *counter)
{
	if (n >= 10)
		ft_putnbr_fd_dec(n / 10, fd, counter);
	ft_putchar_fd_prf(n % 10 + '0', fd, counter);
}
