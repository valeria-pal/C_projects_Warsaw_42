/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:06:40 by vpaliash          #+#    #+#             */
/*   Updated: 2025/06/19 16:40:46 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t server_pid, char c)
{
	int				i;
	unsigned char	bit_mask;

	i = 0;
	while (i < 8)
	{
		bit_mask = 1 << (7 - i);
		if (c & bit_mask)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(400);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Use please : ./client <server_pid> <message>\n");
		return (1);
	}
	server_pid = atoi(argv[1]);
	message = argv[2];
	while (*message)
	{
		send_char(server_pid, *message);
		message++;
	}
	send_char(server_pid, '\0');
	return (0);
}
