# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 14:49:50 by kohmatsu          #+#    #+#              #
#    Updated: 2023/03/23 15:42:55 by kohmatsu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -fsanitize=thread -g
SRCS			= ft_atoi.c info_init.c main.c monitoring.c simulation.c utils.c
OBJS			= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all NAME clean fclean re