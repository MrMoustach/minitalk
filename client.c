/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:54:44 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/09 16:31:42 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minitalk.h"
#include "srcs/client.h"

void	send_char(char c, pid_t pid)
{
	int	i;
	int	k;

	i = 8;
	while (i-- > 0)
	{
		k = c >> i;
		if (k & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
	}
}

int	main(int ac, char *av[])
{
	pid_t	pid;
	int		i;

	if (ac <= 1)
	{
		write (1, "Please provide a valid server pid\n", 34);
		exit(0);
	}
	if (ac <= 2)
	{
		write (1, "Please provide a message\n", 25);
		exit(0);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	while (i < (int) ft_strlen(av[2]))
		send_char(av[2][i++], pid);
	return (0);
}
