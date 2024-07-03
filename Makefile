CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror -g
NAME	:= minitalk
SRC		:= client.c
LIBS	:= ft_printf/libftprintf.a
OBJ		:= $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ) minitalk.h
	make -C ft_printf all
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

clean	:
	make -C ft_printf clean
	rm -f $(OBJ)

fclean	:
	make -C ft_printf fclean
	rm -f $(OBJ) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re