/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:31:12 by andrejarama       #+#    #+#             */
/*   Updated: 2024/07/06 14:37:47 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

# define MAX_BITS 32

typedef struct s_data
{
	char			*str;
	char			current_char;
	int				bit_count;
	int				char_index;
	int				str_len;
	sig_atomic_t	got_len_str;
}	t_data;

#endif // MINITALK_H