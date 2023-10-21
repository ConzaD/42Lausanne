Library		= libftprintf

files 	   = ft_strlen \
			 ft_atoi \
			 ft_putchar_fd \
			 ft_putstr_fd \
			 ft_putnbr_fd \
			 ft_itoa \


Compiler	= gcc

CmpFlags	= -Wall -Wextra -Werror

OUTN	= $(Library).a

CFILES	= $(files:%=%.c)

OFILES	= $(files:%=%.o)

NAME	= libftprintf.a

$(NAME):
	$(Compiler) $(CmpFlags) -c $(CFILES) -I./
	ar rcs libftprintf.a $(OFILES)

all: $(NAME)

clean:
	rm -f $(NAME)
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
