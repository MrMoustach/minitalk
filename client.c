/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:54:44 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/09 13:43:49 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minitalk.h"
#include "srcs/client.h"

int	main(int ac, char *av[])
{
	pid_t pid;
	int	i;
	int	j;
	int c;
	int	interval;

	i = 0;
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
	// TODO : change this
	pid = atoi(av[1]);
	i = 0;
	while (i < ft_strlen(av[2]))
	{
		j = 8;
		c = av[2][i];
		while (j-- > 0)
		{
			int k = c >> j;
			if (k & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(150);
		}
		i++;
	}
	return (0);
}