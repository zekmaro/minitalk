/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:28:26 by andrejarama       #+#    #+#             */
/*   Updated: 2024/07/05 14:56:23 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t got_sig_back = 0;

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
		got_sig_back = 1;
}

void	send_len(char c, pid_t server_pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (c & (1 << i))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		//ft_printf("Sent signal # %d\n", i);
		i++;
		usleep(100);
		while (!got_sig_back)
			pause();
		got_sig_back = 0;
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
			kill(server_pid, SIGUSR1);
			//ft_printf("bit_count %d and the bit 1\n", i);
		}
		else
		{
			kill(server_pid, SIGUSR2);
			//ft_printf("bit_count %d and the bit 0\n", i);
		}
		i++;
		usleep(100);
		while (!got_sig_back)
			pause();
		got_sig_back = 0;
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
	pid_string = ft_itoa(server_pid);
	sa.sa_flags = 0;
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	if (ft_strncmp(pid_string, argv[1], ft_strlen(argv[1])) != 0)
	{
		free(pid_string);
		exit(EXIT_FAILURE);
	}
	send_len(ft_strlen(argv[2]), server_pid);
	send_bit_str(argv[2], server_pid);
	free(pid_string);
}
