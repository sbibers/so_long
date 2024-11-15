CC = cc

CFLAGS = -Wall -Wextra -Werror

X11_FLAGS = -lmlx -lXext -lX11

SRCS = so_long.c putnbr.c check.c put_map.c free.c key.c check_map.c get_next_line.c get_next_line_utils.c

OBJS=$(SRCS:%.c=%.o)

NAME = so_long

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(X11_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re
