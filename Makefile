
DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED		= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m
ORANGE		= \033[38;5;220m
GREEN_BR	= \033[38;5;118m

LIBFT_DIR    = libs/libft/
LIBFT_NAME   = libft.a
LIBFT        = $(LIBFT_DIR)$(LIBFT_NAME)

MINILIBX_PATH = libs/minilibx-linux
MLXFLAGS      = -L$(MINILIBX_PATH) -lmlx -I$(MINILIBX_PATH) -lXext -lX11

NAME          = so_long
CC            = cc
FLAGS         = -Wall -Werror -Wextra -g
SRC           = ./src/main.c ./src/map_utils.c ./src/path.c ./src/move.c ./src/error_handlers.c ./src/free.c ./src/window_utils.c ./libs/get_next_line/get_next_line.c ./libs/get_next_line/get_next_line_utils.c
OBJ           = $(SRC:.c=.o)

# Цели
all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(MAGENTA)Getting libft ready$(DEF_COLOR)"
	@make -s -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@$(RM) $(NAME)
	@echo "$(GREEN_BR)$(NAME) is ready!$(DEF_COLOR)"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS) $(LIBFT)  -s
	

clean:
	@echo "$(YELLOW)Removing libft$(DEF_COLOR)"
	@make clean -s -C $(LIBFT_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(DEF_COLOR)"
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_DIR)$(LIBFT_NAME)

re: fclean all
	@echo "$(BLUE)Cleaned and rebuilt everything for $(NAME).$(DEF_COLOR)"

# Phony targets
.PHONY: all clean fclean re