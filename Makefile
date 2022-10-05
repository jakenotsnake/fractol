# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtanner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 13:11:13 by jtanner           #+#    #+#              #
#    Updated: 2022/09/01 13:33:05 by jtanner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -f
LINKS = -I./includes -L./libft -lft -L./mlx -lmlx -framework OpenGL \
	   	-framework Appkit

SRCS_DIR = srcs/

FILES = Main \
		Mandlebrot \
		Utils \
		event \

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) re -C ./libft
	@$(MAKE) -C ./mlx
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LINKS)

$(OBJS): %.o : %.c
	gcc $(FLAGS) -c -o $@ $< 

clean:
	rm -f $(OBJS)
	@$(MAKE) -C ./libft clean
	@$(MAKE) -C ./mlx clean

fclean:	clean
	rm -f $(NAME)
	@$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: re fclean clean

