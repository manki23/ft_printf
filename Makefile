# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manki <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/16 14:37:29 by manki             #+#    #+#              #
#    Updated: 2019/06/30 14:15:14 by manki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

							#################
							#	VARIABLES	#
							#################

NAME = libftprintf.a

SRC_PATH = ./src
LIB_PATH = ./lib
INC_PATH = ./inc
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

SRC_NAME = ft_printf.c ft_analysis.c ft_utils.c ft_display.c \
		   ft_fill_di_output.c to_do.c

LIB_NAME = ft_atoi.c ft_isdigit.c ft_itoa.c ft_itoa_base.c ft_memchr.c \
		   ft_memcpy.c ft_memset.c ft_putchar.c ft_putstr.c ft_strchr.c \
		   ft_strcmp.c ft_strdel.c ft_strjoin.c ft_strlen.c ft_strncmp.c \
		   ft_strnew.c ft_strsub.c

INC_NAME = ft_printf.h

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

FLAGS = -Wall -Wextra -Werror
CC = gcc

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

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
		@mkdir $(OBJLIB_PATH) 2> /dev/null || true
		@$(CC) $(FLAGS) -o $@ -c $<

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ) $(OBJLIB)
		@echo "$(_GREEN)Building up $(NAME)...$(_END)"
		@ar rc $(NAME) $(OBJ) $(OBJLIB)
		@ranlib $(NAME)
		@echo "$(_GREEN) [OK]$(_END)"

clean:
		@echo "$(_PURPLE)Deleting object files...$(_END)"
		@/bin/rm -f $(OBJ) $(OBJLIB)
		@echo "$(_PURPLE) [OK]$(_END)"

fclean: clean
		@echo "$(_RED)Deleting $(NAME)$(_END)"
		@/bin/rm -rf $(OBJ_PATH) $(NAME)

re: fclean all

norme:
		norminette $(SRC) $(LIB) $(INC)
