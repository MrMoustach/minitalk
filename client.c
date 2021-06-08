/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:54:44 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/08 15:32:57 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minitalk.h"
#include "srcs/client.h"

void	signal_handler(int sig)
{
	printf("got signal");
}

int	main(int ac, char *av[])
{
	pid_t pid;
	int	i;

	pid = atoi(av[1]);
	signal(SIGUSR1, signal_handler);
	printf("%zu", ft_strlen(av[2]));
	i = 0;
	// sending the size
	while (i++ < ft_strlen(av[2]))
	{
		kill(pid, SIGUSR1);
		sleep(1);
	}
	i = 0;
	sleep(1);
	kill(pid, SIGUSR2);
	// end size
	
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR1);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR1);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR1);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR1);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR1);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR1);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR1);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR1);
}