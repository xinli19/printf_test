CC =	cc

FLAG =	-Wall -Wextra 

LFT = 	libft/

LIB =	$(LFT)libft.a

LFSRC =	$(LFT)ft_memset \
		$(LFT)ft_bzero \
		$(LFT)ft_memcpy \
		$(LFT)ft_memmove \
		$(LFT)ft_memcmp \
		$(LFT)ft_memchr \
		$(LFT)ft_strlen \
		$(LFT)ft_strlcpy \
		$(LFT)ft_strlcat \
		$(LFT)ft_strncmp \
		$(LFT)ft_strchr \
		$(LFT)ft_strrchr \
		$(LFT)ft_strnstr \
		$(LFT)ft_strdup \
		$(LFT)ft_atoi \
		$(LFT)ft_isalpha \
		$(LFT)ft_isdigit \
		$(LFT)ft_isalnum \
		$(LFT)ft_isascii \
		$(LFT)ft_isprint \
		$(LFT)ft_toupper \
		$(LFT)ft_tolower \
		$(LFT)ft_calloc \
		$(LFT)ft_strdup \
		$(LFT)ft_substr \
		$(LFT)ft_strjoin \
		$(LFT)ft_strtrim \
		$(LFT)ft_split \
		$(LFT)ft_itoa \
		$(LFT)ft_strmapi \
		$(LFT)ft_putchar_fd \
		$(LFT)ft_putstr_fd \
		$(LFT)ft_putendl_fd \
		$(LFT)ft_putnbr_fd \
		$(LFT)ft_striteri \

FTOB = $(LFSRC:.c=.o)

L =		ar rc

RLIB =	ranlib

LFLAG =	-L libft/ -lft

NAME =	libftprintf.a

SRCS =		ft_itoa.c \
			ft_print_char.c\
			ft_print_hex.c\
			ft_print_int.c\
			ft_print_pointer.c\
			ft_print_str.c\
			ft_print_unsigned.c\
			ft_printf.c \
			ft_strchr.c \
			ft_strlen.c

FDIR = frame/

OBJS =	$(addprefix $(FDIR), $(SRCS:.c=.o))

all: 	$(NAME)

frame:
		@mkdir $(FDIR)
		@echo "$(FDIR): has been created"

$(NAME): $(OBJS) $(LIB)
		@$(L) $(NAME) $(OBJS) $(LFTOB)
		@$(RLIB) $(NAME)
		@echo "$(NAME): has been created"

frame/%.o: %.c | frame
		@$(CC) $(FLAG) -c $< -o $@

$(LIB):
		@make re -C $(LFT)
		@echo "$(LFT): has been created"

clean:
		@rm -f $(OBJS)
		@rm -rf $(FDIR)
		@echo "$(FDIR) & $(OBJS): have been cleaned"

fclean:	clean
		@/bin/rm -f $(NAME)
		@make fclean -C $(LFT)
		@echo "$(NAME) & $(LFT): have been cleaned"

re: fclean all

.PHONY: all clean fclean re