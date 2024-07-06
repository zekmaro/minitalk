/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:28:26 by andrejarama       #+#    #+#             */
/*   Updated: 2024/07/06 14:53:11 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_got_sig_back = 0;

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
		g_got_sig_back = 1;
}

void	send_len(unsigned int len, pid_t server_pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (len & (1U << i))
		{
			if (kill(server_pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		i++;
		usleep(100);
		while (!g_got_sig_back)
			pause();
		g_got_sig_back = 0;
	}
}

void	send_byte(char c, pid_t server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
		{
			if (kill(server_pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		i++;
		usleep(100);
		while (!g_got_sig_back)
			pause();
		g_got_sig_back = 0;
	}
}

void	send_bit_str(char *str, pid_t server_pid)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		send_byte(str[i], server_pid);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	char				*pid_string;
	struct sigaction	sa;

	if (argc != 3)
		exit(EXIT_FAILURE);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		exit(EXIT_FAILURE);
	sa.sa_flags = 0;
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	pid_string = ft_itoa(server_pid);
	if (!pid_string || ft_strncmp(pid_string, argv[1], ft_strlen(argv[1])) != 0)
	{
		free(pid_string);
		exit(EXIT_FAILURE);
	}
	free(pid_string);
	if (ft_strlen(argv[2]))
	{
		send_len((unsigned int)ft_strlen(argv[2]), server_pid);
		send_bit_str(argv[2], server_pid);
	}
}
