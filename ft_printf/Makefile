NAME = libftprintf.a

CFILES =    ft_itoa.c \
			ft_print_char.c\
			ft_print_hex.c\
			ft_print_int.c\
			ft_print_pointer.c\
			ft_print_str.c\
			ft_print_unsigned.c\
			ft_printf.c \
			ft_strchr.c \

OBJECTS = $(CFILES:.c=.o)

MAKE = make

LIB_PATH = ./libft

CC = cc

CFLAGS = -Wall -Wextra -Werror -c

all: subsystem $(NAME)

subsystem:
	$(MAKE) -C $(LIB_PATH)

bonus: all

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS) $(LIB_PATH)/*.o

clean:
	$(MAKE) -C $(LIB_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C $(LIB_PATH) fclean
	rm -f $(NAME)

re: fclean all