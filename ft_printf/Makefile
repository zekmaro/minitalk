NAME := libftprintf.a
CC := cc
CFLAGS := -Wextra -Wall -Werror
SOURCES :=	ft_printf.c ft_putchar_fd.c ft_putnbr_fd_dec.c \
			ft_putnbr_fd_hex_lower.c \
			ft_putnbr_fd_hex_upper.c ft_putnbr_fd_uns.c \
			ft_putstr_fd.c ft_strchr.c ft_memcpy.c \
			ft_putnbr_fd_ptr.c

OBJECTS := $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) ft_printf.h
	ar -rcs $(NAME) $(OBJECTS)

%.o: %.c 
	$(CC) $(CFLAGS) -g -c -o $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)