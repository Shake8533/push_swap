CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC =	./src/initialize.c\
		./src/count_nodes.c\
		./src/free_stack.c\
		./src/push_swap.c\
		./src/sort_stack.c\
		./src/rev_rotate.c\
		./src/input_check.c\
		./src/sort_util.c\
		./src/push_rotate.c\
		./src/swap.c
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
