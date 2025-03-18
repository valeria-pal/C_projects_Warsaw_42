NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRCS = ft_printf.c \
	push_functions.c \
	push_swap.c \
	swap_functions.c \
	rotate_functions.c \
OBJS = $(SRCS:.c=.o)  

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar rc $(NAME) $(OBJS)
	
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