NAME_PUSH_SWAP = push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include/
RM = rm -f
MAKE = make --no-print-directory

SRC_PUSH_SWAP =	./src/utils.c \
				./src/push_swap.c \
				./src/sort_stack.c \
				./src/rev_rotate.c \
				./src/check.c \
				./src/sort_util.c \
				./src/push_rotate.c \
				./src/swap.c
OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)

all: $(NAME_PUSH_SWAP)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME_PUSH_SWAP): $(OBJ_PUSH_SWAP) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_PUSH_SWAP) $(LIBFT) -o $(NAME_PUSH_SWAP)

%.o: %.c include/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_PUSH_SWAP)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME_PUSH_SWAP)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
