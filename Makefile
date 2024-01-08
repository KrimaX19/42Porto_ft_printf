# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 16:48:26 by rusoares          #+#    #+#              #
#    Updated: 2023/11/26 16:48:26 by rusoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

#BONUS = 
#BOBJS = $(BONUS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -c -I.
NAME = libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

#bonus:

PHONY: all bonus clean fclean re