CC = cc

CFLAGS = -Wall -Wextra -Werror -I./include

X11_FLAGS = -I./minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11

SRCS = srcs/so_long.c \
		srcs/check_1.c \
		srcs/check_2.c \
		srcs/ft_free.c \
		srcs/ft_read_map.c \
		srcs/ft_putmap.c \
		srcs/ft_key.c \
		srcs/ft_putnbr.c \
		srcs/get_next_line.c \
		srcs/get_next_line_utils.c \
		srcs/ft_itoa.c \
		srcs/ft_split.c \

OBJ_DIR = objs

OBJS = $(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)

NAME = so_long

all:$(NAME)

$(OBJ_DIR)/%.o:srcs/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(X11_FLAGS) -o $(NAME)
	@echo "\033[0;32mCompile success 😊"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[0;31mRemoved obj directory 😊"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31mRemoved ./so_long 😊"

re:fclean all

.PHONY: all clean fclean re
