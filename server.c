/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:28:22 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/08 15:34:18 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minitalk.h"
#include "srcs/server.h"

void handle_sig(int sig)
{
    if (server.init == 0)
    {
        if (sig == SIGUSR1)
            server.size++;
        else if (sig == SIGUSR2)
            server.init = 1;
    }
    else
    {
        server.current_i++;
        if (sig == SIGUSR1)
            server.buff[server.i] = server.buff[server.i] | 1;
        else if (sig == SIGUSR2)
            server.buff[server.i] = server.buff[server.i] | 0;
        server.buff[server.i] = server.buff[server.i] << 1;
        if (server.current_i == 7)
        {
            server.i++;
            server.current_i = 0;
        }
        if (server.i == 3)
            server.print = 1;
    }
    if (server.init)
        printf("size : %d\n", server.size);
    if (server.print)
    {
        server.print = 0;
        server.i = 0;
        server.current_i = 0;
        write(1, server.buff, 4);
        printf("\n printed \n");
    }
    printf("Caught signal %d\n", sig);
}

int	main(void)
{
    server.i = 0;
    server.current_i = 0;
    server.init = 0;
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	write (1, ft_itoa(getpid()), 6);
    // ch = "🙂";
    write(1, "🙂", 4);
    while (1);
    return 0;
}