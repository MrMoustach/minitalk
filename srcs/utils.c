/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:59:46 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/09 13:20:14 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned	int	tmp;
	char			wtmp;

	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		write (fd, "-", 1);
	}
	if (tmp / 10 > 0)
		ft_putnbr_fd(tmp / 10, fd);
	wtmp = '0' + tmp % 10;
	write (fd, &wtmp, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}
