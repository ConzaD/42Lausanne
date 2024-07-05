# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 18:21:18 by dconza            #+#    #+#              #
#    Updated: 2024/07/05 10:32:32 by dconza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= gcc
LIBFT	= libft/
OBJ_DIR = obj/
SRC_DIR = srcs/

SRC			=	sources/init.c \
				sources/philo.c \
				sources/tools.c \
				sources/main.c

OBJ			= $(SRC:.c=.o)

INCLUDE = -L ./libft -lft
all: $(LIBFT) $(NAME)

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	make -C $(LIBFT)
	${CC} ${CFLAGS} ${OBJ} -o ${NAME} ${INCLUDE}

all: ${NAME}

clean:
	${RM} ${OBJ} ${NAME}
	@cd $(LIBFT) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFT)  && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re
