CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror -g
NAME_1	:= server
SRC_1	:= server.c
NAME_2	:= client
SRC_2	:= client.c
LIBS	:= ft_printf/libftprintf.a libft/libft.a
OBJ_1	:= $(SRC_1:.c=.o)
OBJ_2	:= $(SRC_2:.c=.o)

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJ_1) minitalk.h
	make -C ft_printf all
	make -C libft all
	$(CC) $(CFLAGS) $(OBJ_1) $(LIBS) -o $(NAME_1)

$(NAME_2): $(OBJ_2) minitalk.h
	make -C ft_printf all
	make -C libft all
	$(CC) $(CFLAGS) $(OBJ_2) $(LIBS) -o $(NAME_2)

clean	:
	make -C ft_printf clean
	make -C libft clean
	rm -f $(OBJ_1) $(OBJ_2)

fclean	:
	make -C ft_printf fclean
	make -C libft fclean
	rm -f $(OBJ_1) $(OBJ_2) $(NAME_1) $(NAME_2)

re		: fclean all

.PHONY	: all clean fclean re