/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:37:46 by anarama           #+#    #+#             */
/*   Updated: 2024/04/22 11:09:21 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd, int *counter)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*counter += 6;
		return ;
	}
	while (*s)
	{
		ft_putchar_fd(*s, fd, counter);
		s++;
	}
}
