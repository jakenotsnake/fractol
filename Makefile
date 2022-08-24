# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtanner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 13:11:13 by jtanner           #+#    #+#              #
#    Updated: 2022/08/22 19:00:21 by jtanner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
FLAGS = Wall -Wextra -Werror -g
RM = rm -f
LINKS = -I main.c -L mlx -l mlx -l ft -framework OpenGL \
	   	-framework Appkit

INCS_DIR = includes/
SRCS_DIR = srcs/

FILES = Main \
		Mandlebrot \
		Utils \
		event \

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(SRCS) -o $(NAME) $(FLAGS) $(LINKS)
