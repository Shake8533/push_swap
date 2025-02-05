CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = free_stack.c print_push_swap.c push_swap.c sort_stack.c stack_operations.c verif.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lftprintf -lft -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
