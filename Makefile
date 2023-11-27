# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 19:09:32 by rusoares          #+#    #+#              #
#    Updated: 2023/11/27 19:35:47 by rusoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS:

OBJS = $(SRCS:.c=.o)

BSCRS:

BOBJS = $(BSCRS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a


all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean:
	rm -f $(OBJS) $(BOBJS)

re: fclean all

bonus: $(BOBJS)
	ar rcs $(NAME) $(BOBJS)

PHONY: all clean fclean re
