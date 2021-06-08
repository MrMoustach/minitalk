/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:28:22 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/08 12:19:46 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minitalk.h"
#include "srcs/server.h"

void	signal_handler(int sig)
{
	signal (sig, SIG_DFL);
	printf("got signal");
}

int	main(void)
{
	signal(SIGUSR1, signal_handler);
	// printf("%d", getpid());
	write (1, ft_itoa(getpid()), 4);
	for (;;)
            ;
	return (0);	
}