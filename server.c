/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:28:22 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/09 13:43:54 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minitalk.h"
#include "srcs/server.h"

void	handle_sig(int sig)
{
	server.i++;
	server.buff = server.buff << 1;
	if (sig == SIGUSR1)
		server.buff = server.buff | 1;
	else if (sig == SIGUSR2)
		server.buff = server.buff | 0;
	if (server.i == 8)
	{
		write (1, &server.buff, 1);
		server.buff = 0;
		server.i = 0;
	}
}

int	main(void)
{
	server.i = 0;
	server.buff = 0;
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	ft_putnbr_fd(getpid(), 1);
	write (1, "\n", 1);
	while (1)
		pause();
	return (0);
}
