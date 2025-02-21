NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line_utils.c \
       get_next_line.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)