# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhaoz <muhaoz@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 00:41:53 by muhaoz            #+#    #+#              #
#    Updated: 2025/02/28 23:53:13 by muhaoz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME_CLIENT	= client
NAME_SERVER	= server
SRCS_CLIENT	= client.c ft_printf.c ft_printf_utils.c
SRCS_SERVER	= server.c ft_printf.c ft_printf_utils.c


all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):
	$(CC) $(CFLAGS) $(SRCS_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER):
	$(CC) $(CFLAGS) $(SRCS_SERVER) -o $(NAME_SERVER)

clean:
	@echo "clean target does nothing (no object files to remove)"

fclean:
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all