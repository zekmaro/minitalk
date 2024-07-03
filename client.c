/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:28:26 by andrejarama       #+#    #+#             */
/*   Updated: 2024/07/03 17:23:35 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	ft_printf("Signal received\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				server_pid;
	char				*pid_string;
	if (argc != 3)
		exit(EXIT_FAILURE);
	server_pid = ft_atoi(argv[1]);
	pid_string = ft_itoa(server_pid);
	if (ft_strncmp(pid_string, argv[1], ft_strlen(argv[1])) != 0)
	{
		free(pid_string);
		exit(EXIT_FAILURE);
	}
	ft_printf("server_pid: %d\n", server_pid);
	sa.sa_flags = 0;
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	free(pid_string);
}