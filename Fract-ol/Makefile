# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 19:34:34 by dconza            #+#    #+#              #
#    Updated: 2024/04/16 10:41:34 by dconza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

CC		= gcc
CFLAGS	= -Werror -Wextra -Wall
MLX	= minilibx/
LIBFT	= libft/
OBJ_DIR = obj/
SRC_DIR = srcs/

SRC			=	sources/init.c \
				sources/exit.c \
				sources/execution.c \
				sources/render.c \
				sources/color.c \
				sources/parsing_color.c \
				sources/msg.c \
				sources/mandelbrot.c \
				sources/julia.c \
				sources/color_interpolated.c \
				sources/fractol.c \
				sources/more_color.c \
				sources/striped_color.c \

OBJ			= $(SRC:.c=.o)

INCLUDE = -L ./libft -lft
INCLUDE_1 = -L ./minilibx -lft
all: $(MLX) $(LIBFT) $(NAME)

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	make -C $(LIBFT)
	make -C $(MLX)
	${CC} ${FLAGS} ${OBJ} -o ${NAME} ${INCLUDE}

all: ${NAME}

clean:
	${RM} ${OBJ_1} ${NAME}
	@cd $(LIBFT) && $(MLX) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFT) && $(MLX) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re
