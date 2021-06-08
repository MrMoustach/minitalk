/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:54:44 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/08 12:16:30 by iharchi          ###   ########.fr       */
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

	pid = atoi(av[1]);
	signal(SIGUSR1, signal_handler);
	printf("%d", pid);
	kill(pid, SIGUSR1);
}