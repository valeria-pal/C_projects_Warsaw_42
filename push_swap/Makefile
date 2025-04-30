NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I.

SRCS = \
	main.c \
	push_swap.c \
	sort_small.c \
	stack_implemetation.c \
	swap_functions.c \
	push_functions.c \
	rotate_functions.c \
	reverse_rotate_functions.c \
	free_function.c \
	input_checkers.c \
	ft_printf.c\
	sort_preparation.c
	

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
