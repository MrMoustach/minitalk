# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 10:24:43 by iharchi           #+#    #+#              #
#    Updated: 2021/06/08 11:25:56 by iharchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
SRCS_CLIENT = srcs/*.c
SRCS_SERVER = srcs/*.c
FLAG = -Wall -Werror -Wextra

serv: 
		@gcc server.c $(SRCS_SERVER) -o $(SERVER)
cli:
		@gcc client.c $(SRCS_CLIENT) -o $(CLIENT)

all: serv cli

clean:
	

fclean: clean
	@/bin/rm -f $(SERVER) $(CLIENT)

re : fclean all