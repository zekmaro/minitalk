/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:17:12 by anarama           #+#    #+#             */
/*   Updated: 2024/05/23 21:27:00 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

char	*ft_strchr_prf(char *str, char c);
void	ft_putchar_fd_prf(char c, int fd, int *counter);
void	ft_putstr_fd_prf(char *s, int fd, int *counter);
void	ft_putnbr_fd_dec(int n, int fd, int *counter);
void	ft_putnbr_fd_hex_lower(size_t n, int fd, int *counter);
void	ft_putnbr_fd_hex_upper(size_t n, int fd, int *counter);
void	ft_putnbr_fd_uns(size_t n, int fd, int *counter);
void	*ft_memcpy_prf(void *dest, const void *src, size_t n);
void	ft_putnbr_fd_ptr(ssize_t n, int fd, int *counter, int flag);
int		ft_printf(const char *str, ...);

#endif