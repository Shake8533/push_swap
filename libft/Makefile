CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME_PRINTF = libftprintf.a
SRC_PRINTF = ft_printf.c ft_printf_utils.c
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

NAME_LIBFT = libft.a
SRCS_LIBFT = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
             ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
             ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
             ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
             ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
             ft_striteri.c ft_strmapi.c ft_strtrim.c ft_substr.c \
             ft_strjoin.c ft_split.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c \
             ft_putendl_fd.c ft_putnbr_fd.c
OBJ_LIBFT = $(SRCS_LIBFT:.c=.o)

all: $(NAME_LIBFT) $(NAME_PRINTF)

$(NAME_PRINTF): $(OBJ_PRINTF)
	ar rcs $(NAME_PRINTF) $(OBJ_PRINTF)

$(NAME_LIBFT): $(OBJ_LIBFT)
	ar rcs $(NAME_LIBFT) $(OBJ_LIBFT)

%.o: %.c ft_printf.h ft_libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_PRINTF) $(OBJ_LIBFT)

fclean: clean
	rm -f $(NAME_PRINTF) $(NAME_LIBFT)

re: fclean all

.PHONY: all clean fclean re
