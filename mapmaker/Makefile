# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/08 14:20:14 by aderby            #+#    #+#              #
#    Updated: 2017/09/21 16:13:30 by aderby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = map_maker

C_FIL = main.c initialize.c hooks.c mouse_hooks.c save.c

O_FIL = $(C_FIL:.c = .o)

O_LOC = obj

GCC_FLAGS = gcc -L miniLibx -lmlx -framework OpenGL \
			-framework AppKit

LIB = libft/libft.a

MLX = miniLibx/libmlx.a

all: $(NAME)

$(LIB):
	cd libft && make

$(MLX):
	cd miniLibx && make

$(NAME): $(O_FIL) $(LIB) $(MLX)
	$(GCC_FLAGS) $(LIB) $^ -o $(NAME)

%.o: %.c ./wolf3d.h
	gcc -c $< -o $@

clean:
		cd libft && make clean

fclean: clean
		cd libft && make fclean
			/bin/rm -f $(NAME)

test: $(NAME)
	./wolf3d

re: fclean all
