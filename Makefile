# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bano <bano@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/17 16:13:57 by notraore          #+#    #+#              #
#    Updated: 2019/01/31 08:14:37 by bano             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	scop
LIBFT 		= 	libft/libft.a

SRCS		= 	main.c

OBJS		= 	$(patsubst srcs/%.c,objs/%.o,$(SRCS))

CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror
INC			=	-I./includes/
FRMWK		=	-framework OpenGl -lglfw -lGLEW

CG = \033[92m
CY = \033[93m
CE = \033[0m

all:		$(NAME)

$(NAME):	$(OBJS)
			@ make -C ./libft all
			@ $(CC) $(LIBFT) $(FRMWK) -o $@ $^
			@ echo "\n\033[92m---> scop program created ✓\033[0m";

objs/%.o:	srcs/%.c
			@ mkdir -p objs
		 	@ $(CC) $(INC) -c $< -o $@
		 	@ echo "\033[K$(CY)[RT] :$(CE) $(CG)Compiling $<$(CE) \033[1A";

clean:		
			@ make -C libft/ clean
			@ /bin/rm -rf objs/
			@ echo "\033[1;33m---> All .o files cleared\033[0m \033[92m✓\033[0m";

fclean:		clean
			@ /bin/rm -f $(NAME)
			@ make -C libft/ fclean
			@ echo "\n\033[1;33m---> Everything cleared\033[2;00m \033[92m✓\033[0m";
re : fclean all

.PHONY: all, clean, fclean, re
