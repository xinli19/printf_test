NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

CODES = ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memmove \
		ft_memcmp \
		ft_memchr \
		ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strncmp \
		ft_strchr \
		ft_strrchr \
		ft_strnstr \
		ft_strdup \
		ft_atoi \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_striteri \
		ft_puthex_lower \
		ft_putpointer \
		ft_puthex_upper \
		ft_put_unsigned \
		ft_printf \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(CODES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(CODES)))


.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re