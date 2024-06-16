NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c operations.c stack_utils.c
OBJ = $(SRC:.c=.o)
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re