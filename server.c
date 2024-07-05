/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:16:37 by anarama           #+#    #+#             */
/*   Updated: 2024/07/05 16:15:32 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	*str = NULL;
    static char	current_char = 0;
    static int	bit_count = 0;
    static int	char_index = 0;
	static int	str_len = 0;

	(void) context;
	if (!got_len_str)
	{
		if (sig == SIGUSR1)
		{
			str_len |= (1 << bit_count);
		}
		usleep(100);
		kill(info->si_pid, SIGUSR1);
		if (bit_count == MAX_BITS - 1)
		{
			got_len_str = 1;
			str = ft_calloc(str_len + 1, sizeof(char));
			if (!str)
				exit(EXIT_FAILURE);
			bit_count = 0;
		}
		else
		{
			bit_count++;
			return ;
		}
	}
	else
	{
		if (sig == SIGUSR1)
		{
			current_char |= (1 << bit_count);
			ft_printf("%d 1\n", bit_count);
		}
		else {
			ft_printf("%d 0\n", bit_count);
		}
		usleep(100);
		kill(info->si_pid, SIGUSR1);
		if (bit_count == 7)
		{
			bit_count = 0;
			str[char_index] = current_char;
			current_char = 0;
			char_index++;
			ft_printf("\n");
		}
		else
			bit_count++;
		if (char_index == str_len)
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
			char_index = 0;
			str_len = 0;
			got_len_str = 0;
		}
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
    sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
