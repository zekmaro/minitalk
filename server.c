/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:16:37 by anarama           #+#    #+#             */
/*   Updated: 2024/07/06 14:57:12 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data = {0};

void	print_minitalk(void)
{
	ft_printf("███╗░░░███╗██╗███╗░░██╗██╗████████╗░█████╗░██╗░░░░░██╗░░██╗\n");
	ft_printf("████╗░████║██║████╗░██║██║╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝\n");
	ft_printf("██╔████╔██║██║██╔██╗██║██║░░░██║░░░███████║██║░░░░░█████═╝░\n");
	ft_printf("██║╚██╔╝██║██║██║╚████║██║░░░██║░░░██╔══██║██║░░░░░██╔═██╗░\n");
	ft_printf("██║░╚═╝░██║██║██║░╚███║██║░░░██║░░░██║░░██║███████╗██║░╚██╗\n");
	ft_printf("╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝\n");
}

int	handle_content_signal(int sig, siginfo_t *info)
{
	if (sig == SIGUSR1)
	{
		g_data.current_char |= (1 << g_data.bit_count);
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		return (0);
	if (g_data.bit_count == 7)
	{
		g_data.bit_count = 0;
		(g_data.str)[g_data.char_index] = g_data.current_char;
		g_data.current_char = 0;
		(g_data.char_index)++;
	}
	else
		(g_data.bit_count)++;
	if (g_data.char_index == g_data.str_len)
	{
		ft_printf("%s\n", g_data.str);
		free(g_data.str);
		g_data.str = NULL;
		g_data.char_index = 0;
		g_data.str_len = 0;
		g_data.got_len_str = 0;
	}
	return (1);
}

int	handle_len_signal(int sig, siginfo_t *info)
{
	if (sig == SIGUSR1)
	{
		g_data.str_len |= (1U << g_data.bit_count);
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		return (0);
	if (g_data.bit_count == MAX_BITS - 1)
	{
		g_data.got_len_str = 1;
		g_data.str = ft_calloc(g_data.str_len + 1, sizeof(char));
		if (!g_data.str)
			exit(EXIT_FAILURE);
		g_data.bit_count = 0;
	}
	else
	{
		(g_data.bit_count)++;
	}
	return (1);
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void) context;
	if (!g_data.got_len_str)
	{
		if (!handle_len_signal(sig, info))
		{
			free(g_data.str);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!handle_content_signal(sig, info))
		{
			free(g_data.str);
			exit(EXIT_FAILURE);
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
