# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manki <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 08:28:02 by manki             #+#    #+#              #
#    Updated: 2018/01/04 13:33:39 by manki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
## VARIABLES ##
###############

NAME = libft.a

SRCS += ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strcpy.c ft_strncpy.c \
		ft_strdup.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c

SRCS += ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS += ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		ft_lstmap.c

SRCS += ft_lstlen.c ft_list_push_front.c ft_list_push_back.c \
		ft_strrev.c ft_sort_integer_table.c ft_sort_wordtab.c \
		ft_print_words_tables.c ft_isblank.c ft_iscntrl.c ft_isgraph.c \
		ft_islower.c ft_isspace.c ft_isupper.c ft_isxdigit.c ft_str_is_alpha.c \
		ft_str_is_lowercase.c ft_str_is_numeric.c ft_str_is_printable.c \
		ft_str_is_uppercase.c ft_strlowcase.c ft_strupcase.c \
		ft_strcapitalize.c ft_strcasecmp.c ft_strncasecmp.c ft_strcasestr.c \
		ft_strlcpy.c ft_strndup.c ft_putnbr_base.c ft_sqrt.c ft_abs.c \
		ft_isprime.c ft_realloc.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

############
## COLORS ##
############

_GREY	=	$ \033[30m
_RED	=	$ \033[31m
_GREEN	=	$ \033[32m
_YELLOW	=	$ \033[33m
_BLUE	=	$ \033[34m
_PURPLE	=	$ \033[35m
_CYAN	=	$ \033[36m
_WHITE	=	$ \033[37m
_END	=	$ \033[0m

.PHONY: all clean

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $?

$(NAME): $(OBJ)
	@echo "$(_GREEN)	Creation de libft.a$(_END)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@echo "$(_PURPLE)	Suppression des fichiers objets$(_END)"
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "$(_RED)	Suppression de libft.a$(_END)"
	@/bin/rm -f $(NAME)

re: fclean all
