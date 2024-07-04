/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:16:37 by anarama           #+#    #+#             */
/*   Updated: 2024/07/04 16:50:09 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

static volatile sig_atomic_t got_len_str = 0;

void	print_minitalk()
{
	ft_printf("███╗░░░███╗██╗███╗░░██╗██╗████████╗░█████╗░██╗░░░░░██╗░░██╗\n");
	ft_printf("████╗░████║██║████╗░██║██║╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝\n");
	ft_printf("██╔████╔██║██║██╔██╗██║██║░░░██║░░░███████║██║░░░░░█████═╝░\n");
	ft_printf("██║╚██╔╝██║██║██║╚████║██║░░░██║░░░██╔══██║██║░░░░░██╔═██╗░\n");
	ft_printf("██║░╚═╝░██║██║██║░╚███║██║░░░██║░░░██║░░██║███████╗██║░╚██╗\n");
	ft_printf("╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝\n");
}

void	add_char_to_str(char *str)
{
	if (str != NULL)
	{
		str = ft_calloc(2, sizeof(char));
		if (!str)
		{
			exit(EXIT_FAILURE);
		}
	}
	
	
}

int	get_str_len(int sig, int bit_count, int *str_len)
{
	if (got_len_str == 0)
	{
		if (sig == SIGUSR1)
			*str_len |= (1 << bit_count);
		bit_count++;
	}
	return (bit_count);
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	*str = NULL;
    static char	current_char = 0;
    static int	bit_count = 0;
    static int	char_index = 0;
	static int	str_len = 0;

	if (!got_len_str)
	{
		bit_count = get_str_len(sig, bit_count, &str_len);
		if (bit_count == MAX_BITS)
		{
			got_len_str = 1;
			str = ft_calloc(str_len + 1, sizeof(char));
			if (!str)
				exit(EXIT_FAILURE);
		}
		return ;
	}
	while ()
	{
		
	}	
	
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	print_minitalk();
	pid = getpid();
	ft_printf("%d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
	{
		pause();
	}
}
