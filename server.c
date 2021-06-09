/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:28:22 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/09 15:12:10 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minitalk.h"
#include "srcs/server.h"

void	handle_sig(int sig)
{
	g_server.i++;
	g_server.buff = g_server.buff << 1;
	if (sig == SIGUSR1)
		g_server.buff = g_server.buff | 1;
	else if (sig == SIGUSR2)
		g_server.buff = g_server.buff | 0;
	if (g_server.i == 8)
	{
		write (1, &g_server.buff, 1);
		g_server.buff = 0;
		g_server.i = 0;
	}
}

int	main(void)
{
	g_server.i = 0;
	g_server.buff = 0;
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	ft_putnbr_fd(getpid(), 1);
	write (1, "\n", 1);
	while (1)
		pause();
	return (0);
}
