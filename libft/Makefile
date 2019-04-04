# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: notraore <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 13:32:42 by notraore          #+#    #+#              #
#    Updated: 2019/03/11 10:21:42 by arive-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=gcc
FLAGS=-Werror -Wextra -Wall
SRC_PATH=./srcs/
SRC=ft_itoa.c ft_memmove.c ft_putnbr_fd.c ft_strcpy.c ft_strlcat.c ft_strnequ.c ft_atoi.c\
ft_memalloc.c ft_memset.c ft_putstr.c ft_strdel.c ft_strlen.c ft_strnew.c ft_bzero.c\
ft_memccpy.c ft_putchar.c ft_putstr_fd.c ft_strdup.c ft_strmap.c ft_strnstr.c\
ft_isalnum.c ft_memchr.c ft_putchar_fd.c ft_strcat.c ft_strequ.c ft_strmapi.c ft_strrchr.c\
ft_isascii.c ft_memcmp.c ft_putendl.c ft_strchr.c ft_striter.c ft_strncat.c ft_strsplit.c\
ft_isprint.c ft_memcpy.c ft_putendl_fd.c ft_strclr.c ft_striteri.c ft_strncmp.c ft_strsub.c\
ft_memdel.c ft_putnbr.c ft_strcmp.c ft_strjoin.c ft_strncpy.c ft_strtrim.c ft_is_prime.c\
ft_find_next_prime.c ft_strcapitalize.c ft_isdigit.c ft_isalpha.c ft_strstr.c ft_toupper.c\
ft_tolower.c ft_strlowcase.c ft_isspace.c ft_split.c ft_strcount.c ft_lstnew.c ft_lstadd.c\
get_next_line.c ft_lstiter.c ft_lstdel.c ft_lstdelone.c ft_lstmap.c ft_kill.c free_tab.c\
ft_atof.c ft_atod.c pos_atoi.c tab_len.c ft_count_c.c pos_atof.c my_atoi.c
HEADER_PATH=./includes/
FULL_PATH=$(SRC)
OBJ=ft_itoa.o ft_memmove.o ft_putnbr_fd.o ft_strcpy.o ft_strlcat.o ft_strnequ.o ft_atoi.o\
ft_memalloc.o ft_memset.o ft_putstr.o ft_strdel.o ft_strlen.o ft_strnew.o ft_bzero.o\
ft_memccpy.o ft_putchar.o ft_putstr_fd.o ft_strdup.o ft_strmap.o ft_strnstr.o\
ft_isalnum.o ft_memchr.o ft_putchar_fd.o ft_strcat.o ft_strequ.o ft_strmapi.o ft_strrchr.o\
ft_isascii.o ft_memcmp.o ft_putendl.o ft_strchr.o ft_striter.o ft_strncat.o ft_strsplit.o\
ft_isprint.o ft_memcpy.o ft_putendl_fd.o ft_strclr.o ft_striteri.o ft_strncmp.o ft_strsub.o\
ft_memdel.o ft_putnbr.o ft_strcmp.o ft_strjoin.o ft_strncpy.o ft_strtrim.o ft_is_prime.o\
ft_find_next_prime.o ft_strcapitalize.o ft_isdigit.o ft_isalpha.o ft_strstr.o ft_toupper.o\
ft_tolower.o ft_strlowcase.o ft_isspace.o ft_split.o ft_strcount.o ft_lstnew.o ft_lstadd.o\
get_next_line.o ft_lstiter.o ft_lstdel.o ft_lstdelone.o ft_lstmap.o ft_kill.o free_tab.o\
ft_atof.o ft_atod.o pos_atoi.o tab_len.o ft_count_c.o pos_atof.o my_atoi.o
HEADER_PATH=./includes/
all: $(NAME)
$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
$(OBJ): $(FULL_PATH)
	@$(CC) -c $(FLAGS) -I$(HEADER_PATH) $(FULL_PATH)
clean:
	@rm -f $(OBJ)
	@echo "Cleared .o files"
fclean: clean
	@rm -f $(OBJ) $(NAME)
	@echo "Everything is cleared"
re: fclean all
