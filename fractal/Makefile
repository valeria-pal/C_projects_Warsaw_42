NAME = fractal

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I.
MINI_LIBX_FLAGS = -L$(MINI_LIBX_DIR) -lmlx -lX11 -lXext -lm


SRCS = \
	main.c \
	

	

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MINI_LIBX_DIR = minilibx
MINI_LIBX = $(MINI_LIBX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINI_LIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINI_LIBX) $(MINI_LIBX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINI_LIBX):
	$(MAKE) -C $(MINI_LIBX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINI_LIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MINI_LIBX_DIR) clean

re: fclean all

.PHONY: all clean fclean re