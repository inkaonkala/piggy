NAME = solong.a

SRC =	main.c start.c entering_screen.c valid_map.c render_map.c key_commands.c image_settings.c clean_n_errors.c piggy.c draw_trees.c bonus_enemy.c

OBJ = $(SRC:.c=.o)

CC	= gcc

FLAGS	= -Wall -Wextra -Werror

INCLUDES = -I/Users/inka/Desktop/Code/pelit/newtry/mlx \
			-I/Users/inka/Desktop/Code/libft

MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
LIBFT_FLAGS = -L/Users/inka/Desktop/Code/libft -lft

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
