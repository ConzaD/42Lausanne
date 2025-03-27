# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 16:28:50 by dconza            #+#    #+#              #
#    Updated: 2025/02/14 16:28:51 by dconza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = *.cpp
NAME = zombie
CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all