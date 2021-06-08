/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:59:46 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/08 12:00:15 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	char	*zero(void)
{
	char	*ret;

	ret = (char *)malloc(2);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

static	int		calculate(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static	int		det_n(unsigned int *tmp, int n)
{
	if (n < 0)
	{
		*tmp = -n;
		return (1);
	}
	*tmp = (unsigned int)n;
	return (0);
}

char			*ft_itoa(int n)
{
	int				len;
	int				signe;
	unsigned	int	tmp;
	char			*ret;

	len = 0;
	signe = 0;
	tmp = n;
	if (n == 0)
		return (ret = zero());
	else
		signe = det_n(&tmp, n);
	len = calculate(tmp);
	if (!(ret = (char *)malloc(len + signe + 1)))
		return (NULL);
	*(ret + len-- + signe) = '\0';
	while (tmp > 0)
	{
		*(ret + len + signe) = tmp % 10 + '0';
		len--;
		tmp /= 10;
	}
	if (signe)
		*ret = '-';
	return (ret);
}