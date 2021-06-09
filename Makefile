# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iharchi <iharchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 10:24:43 by iharchi           #+#    #+#              #
#    Updated: 2021/06/09 15:15:24 by iharchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
SRCS = srcs/*.c
FLAG = -Wall -Werror -Wextra

objects = server client
all: $(objects)

$(objects): %: %.c
		gcc $(FLAG) $(SRCS) $ -o $@ $<

clean:
	

fclean: clean
	@/bin/rm -f $(SERVER) $(CLIENT)

re : fclean all