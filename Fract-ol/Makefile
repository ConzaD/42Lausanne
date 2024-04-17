# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 19:34:34 by dconza            #+#    #+#              #
#    Updated: 2024/04/17 15:20:14 by dconza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
OS		= $(shell uname)

# directories
SRCDIR	= ./sources
INCDIR	= ./includes
OBJDIR	= ./obj

SRC			=	init.c \
				exit.c \
				execution.c \
				render.c \
				color.c \
				parsing_color.c \
				msg.c \
				mandelbrot.c \
				julia.c \
				color_interpolation.c \
				fractol.c \
				more_color.c \
				striped_color.c \
				$(addprefix fractals/,$(shell ls $(SRCDIR)/fractals | grep -E ".+\.c"))

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g


# mlx library
ifeq ($(OS), Linux)
	MLX		= ./miniLibX_X11/
	MLX_LNK	= -L $(MLX) -l mlx -lXext -lX11
else
	MLX		= ./miniLibX/
	MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit
endif

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),mlx.a)

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft -l pthread

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/fractals

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
