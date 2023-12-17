# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 12:20:25 by dconza            #+#    #+#              #
#    Updated: 2023/12/17 19:49:56 by dconza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
HEADER = push_swap.h
RM = rm -f
FLAGS = -Wall -Wextra -Werror
OBJ_DIR = obj/
SRC_DIR = sources/

SRC_1 = sources/push_swap.c \

SRC_2 =	sources/checkeur.c \
		sources/checkeur_bis.c \
		sources/ft_add.c \
		sources/function_rotate.c \
		sources/operation_stack.c \
		sources/rules_1.c \
		sources/rules_2.c \
		sources/rules_3.c \
		sources/rules_4.c \
		sources/solver_utils.c \
		sources/solver_utils_bis.c \
		sources/solver.c \
		sources/sort.c \
		sources/utils.c \
		sources/utils_bis.c \
		sources/test.c \

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}

all: ${NAME} $

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME}

fclean: clean
	${RM} ${NAME}

re: clean all

.PHONY: all clean fclean re
