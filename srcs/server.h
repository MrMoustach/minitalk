/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:29:34 by iharchi           #+#    #+#             */
/*   Updated: 2021/06/08 15:28:36 by iharchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <signal.h>
# include <stdio.h>

typedef struct  s_server
{
		char	buff[5];
		int		i;
		int		current_i;
		int		size;
		int		init;
		int		print;
}               t_server;
t_server server;
#endif