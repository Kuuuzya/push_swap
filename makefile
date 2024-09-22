NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
SRC = push_swap.c operations.c operations_2.c operations_3.c stack_utils.c ft_utils.c validation.c sort_small.c \
sort_utils.c sort_big.c do_operations.c do_operations_2.c do_operations_3.c
OBJ = $(SRC:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re