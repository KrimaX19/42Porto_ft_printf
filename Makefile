# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 16:48:26 by rusoares          #+#    #+#              #
#    Updated: 2024/04/19 22:52:43 by rusoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

#BONUS = 
#BOBJS = $(BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c 
NAME = libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all
#so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
#	cc -nostartfiles -shared -o libft.so $(OBJS)

#bonus:
