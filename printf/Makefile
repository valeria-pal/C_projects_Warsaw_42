NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	print_functions.c \
	ft_handle_specifiers.c
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


       
