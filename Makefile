CC = cc

CFLAGS =  -g3 -Wall -Wextra -Werror

INCLUDE = -I ./include -I ./Libft -I $(MLX_DIR)
DIRLIB = ./libft/
FILELIB = libft.a
NAMELFT = $(addprefix $(DIRLIB), $(FILELIB))

MLX_REPO_LINUX = https://github.com/42Paris/minilibx-linux.git
MLX_REPO_MACOS = https://github.com/42Paris/minilibx-macos.git
MLX_DIR = ./minilibx
MLX_LIB = $(MLX_DIR)/libmlx.a

MLX_FLAGS_LINUX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
MLX_FLAGS_MACOS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

OS := $(shell uname)
ifeq ($(OS), Darwin)
    MLX_REPO = $(MLX_REPO_MACOS)
    MLX_FLAGS = $(MLX_FLAGS_MACOS)
else
    MLX_REPO = $(MLX_REPO_LINUX)
    MLX_FLAGS = $(MLX_FLAGS_LINUX)
endif

MAKEFLAGS += --no-print-directory
RM = rm -f
VGCORE_FILES = vgcore.*
NAME = cub3d

PARSING_SRC = 

MATH_SRC = minimap.c raycasting.c

UTILS_SRC = len_utils.c keyhook.c get_next_line.c utils.c

CUB3D_SRC = main.c $(PARSING_SRC) $(MATH_SRC) $(UTILS_SRC)

all: $(NAME)

mlx :
				git clone https://github.com/42Paris/minilibx-linux.git minilibx
				@cd minilibx && ./configure

$(NAMELFT):
	@echo "Clonage et compilation de la libft..."
	@if [ ! -d "$(DIRLIB)" ]; then git clone https://github.com/YOUR_GITHUB/libft.git $(DIRLIB); fi
	@$(MAKE) -C $(DIRLIB)

$(MLX_DIR):
	@echo "Clonage de la MiniLibX..."
	@if [ ! -d "$(MLX_DIR)" ]; then git clone $(MLX_REPO) $(MLX_DIR); fi

$(MLX_LIB): $(MLX_DIR)
	@echo "Compilation de la MiniLibX..."
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(CUB3D_SRC)
	@echo -e '\033[35mCreating Cub3d... 🕗\n'
	@$(MAKE) -C $(DIRLIB)
	@$(CC) $(CFLAGS) $(CUB3D_SRC) $(NAMELFT) $(INCLUDE) $(MLX_FLAGS) -o $(NAME)
	@echo -e '\033[33;32mCub3d created ! 🎉\033[0m'

clean:
	@$(MAKE) -C $(DIRLIB) clean
	@$(RM) $(NAME)
	@echo -e '\033[0;31mCub3d deleted ! 🛑'

fclean: clean
	@$(MAKE) -C $(DIRLIB) fclean
	@$(RM) $(VGCORE_FILES)

re: fclean all

.PHONY: all clean fclean re
