NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I.

SRCS = ft_printf.c \
	main.c \
	input_checkers.c \
	stack_implemetation.c\
	free_function.c\
	swap_functions.c\
	push_functions.c\
	rotate_functions.c\
	reverse_rotate_functions.cc
	
OBJS = $(SRCS:.c=.o)  

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	
$(LIBFT):
	cd $(LIBFT_DIR) && $(MAKE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
        
clean:
	rm -f $(OBJS)

fclean: clean
	cd $(LIBFT_DIR) && $(MAKE) fclean
	rm -f $(NAME)	 

re: fclean all