CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -I ./include -I ./Libft
DIRLIB = ./libft/
FILELIB = libft.a
NAMELFT = $(addprefix $(DIRLIB), $(FILELIB))

MAKEFLAGS += --no-print-directory
RM = rm -f
VGCORE_FILES = vgcore.*
NAME = minishell

PARSING_SRC = 

MAIN_SRC = 

UTILS_SRC = 

CUB3D_SRC = main.c $(PARSING_SRC) $(MAIN_SRC) $(UTILS_SRC)

# ASCII_LOGO = -e "\
# 	███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     \n\
# 	████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     \n\
# 	██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     \n\
# 	██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     \n\
# 	██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗\n\
# 	╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝"

all: $(NAMELFT) $(NAME)

$(NAMELFT):
	@echo "Compilation de la libft..."
	@$(MAKE) -C $(DIRLIB)

$(NAME): $(CUB3D_SRC) $(NAMELFT)
	@echo -e '\033[35mCreating Cub3d... 🕗\n'
	@echo $(ASCII_LOGO)
	@$(CC) $(CFLAGS) $(CUB3D_SRC) $(NAMELFT) $(INCLUDE) -o $(NAME)
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