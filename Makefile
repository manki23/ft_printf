# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manki <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/16 14:37:29 by manki             #+#    #+#              #
#    Updated: 2018/05/16 17:29:28 by manki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

							#################
							#	VARIABLES	#
							#################

NAME = libftprintf.a

SRCS = ft_printf.c

INCLUDES = ./includes/ ./sources/

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

							#############
							#	COLORS	#
							#############

_GREY=			$ \033[30m
_RED=			$ \033[31m
_GREEN=			$ \033[32m
_YELLOW=		$ \033[33m
_BLUE=			$ \033[34m
_PURPLE=		$ \033[35m
_CYAN=			$ \033[36m
_WHITE=			$ \033[37m
_END=			$ \033[0m

.PHONY: all clean libft fclean re

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -I $(INCLUDES) -c $?

libft:
		@echo "$(_GREEN)Building up libft.a$(_END)"
		@make -C libft all

$(NAME): libft $(OBJ)
		@echo "$(_GREEN)Building up $(NAME)$(_END)"
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

clean:
		@echo "$(_PURPLE)Deleting object files$(_END)"
#		/bin/rm -f $(OBJ)
		@make -C libft clean

fclean: clean
		@echo "$(_RED)Deleting $(NAME)$(_END)"
		@/bin/rm -f $(NAME)
		@make -C libft fclean

re: fclean all
