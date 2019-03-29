# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bano <bano@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/17 16:13:57 by notraore          #+#    #+#              #
#    Updated: 2019/03/13 15:43:12 by bano             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	scop
LIBFT 		= 	libft/libft.a
FRMWLIB		= 	lib/libglfw.3.2.dylib
GLADLIB		=	glad/libglad.a

SRCS		= 	main.c \
				input_key.c \
				functions.c \
				frames_counter.c \
				checker.c \
				shader.c \
				textures.c \
				render_model.c\
				matrix.c \
				init.c \
				bmp_parser.c \
				vector.c \
				matrice.c \
				rotation.c \
				faces_parser.c \
				parser.c

OBJS		= 	$(patsubst srcs/%.c,objs/%.o,$(SRCS))

CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror
FRMPATH		=	-I./include/GLFW/
GLADPATH	=	-I./glad/
FRMWK		=	-framework OpenGl 

CG = \033[92m
CY = \033[93m
CE = \033[0m

all:		$(NAME)

$(NAME):	$(OBJS)
			@ make -C ./libft all
			@ $(CC) $(LIBFT) $(CFLAGS) $(GLADPATH) $(FRMPATH) $(SCOPINC) $(FRMWLIB) $(GLADLIB) $(FRMWK) -o $@ $^
			@ echo "\n\033[92m---> scop program created ✓\033[0m";

objs/%.o:	srcs/%.c
			@ mkdir -p objs
		 	@ $(CC) -c $< -o $@
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
