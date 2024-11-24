CC = cc

CFLAGS = -Wall -Wextra -Werror -I./include

X11_FLAGS = -I./minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11
# what is the X11 : allows linux display graphical interface.
# componentes of X11 ? 1) client (application) server : control the screen, the client are the apps (web browser) client send request to X server, X server takes care to showing on the screen.
# 2) X server : handle the screen and input device (keyboard/mous) like X.Org.
# 3) Window manager : control how windows look.
# -lmlx : for library mlx, -lXext : for X Extensions library, -lX11 : for X11 that allows to connect with X widnow system.

SRCS = srcs/so_long.c \
		srcs/check_1.c \
		srcs/check_2.c \
		srcs/ft_free.c \
		srcs/ft_read_map.c \
		srcs/ft_putmap.c \
		srcs/ft_key.c \
		srcs/ft_strcpy.c \
		srcs/ft_putnbr.c \
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
