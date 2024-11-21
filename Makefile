CC = cc

CFLAGS = -Wall -Wextra -Werror -I./include

X11_FLAGS = -lmlx -lXext -lX11
#-lmlx : for library mlx, -lXext : for library Xext for X11, -lX11 : for X11.

SRCS = srcs/so_long.c \
		srcs/check.c \
		srcs/check_map.c \
		srcs/ini_read.c \
		srcs/free.c \
		srcs/put_map.c \
		srcs/key.c \
		srcs/putnbr.c \
		srcs/get_next_line.c \
		srcs/get_next_line_utils.c \
		srcs/ft_itoa.c \

OBJ_DIR = objs
# directory for objects file.

OBJS = $(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)
# convert .c files to .o files to the path OBJ_DIR.

NAME = so_long

all:$(NAME)

$(OBJ_DIR)/%.o:srcs/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
# mkdir -p $(OBJ_DIR) : make the OBJ_DIR if it not existing.
# $(CC) $(CFLAGS) -c $< -o $@ : ($<) for .c files, ($@) for .o files. 
# -c : translating the code into code (.o) without linking it.
# -o : the result will be a file named laike .c file just .o file.
$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(X11_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re
