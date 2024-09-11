LIBFT_DIR    = libs/libft/
LIBFT_NAME   = libft.a
LIBFT        = $(LIBFT_DIR)$(LIBFT_NAME)

MINILIBX_PATH = libs/minilibx
MLXFLAGS      = -L$(MINILIBX_PATH) -lmlx -I$(MINILIBX_PATH) -framework OpenGL -framework AppKit

NAME          = so_long
CC = gcc
CFLAGS = -Wall -O2 -g
SRC           = ./src/main.c ./src/map_utils.c ./src/path.c ./src/move.c ./src/error_handlers.c ./src/free.c ./src/window_utils.c ./libs/get_next_line/get_next_line.c ./libs/get_next_line/get_next_line_utils.c
OBJ           = $(SRC:.c=.o)

# Цели
all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(MAGENTA)Getting libft ready$(DEF_COLOR)"
	@make  -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@$(RM) $(NAME)
	@echo "$(GREEN_BR)$(NAME) is ready!$(DEF_COLOR)"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS) $(LIBFT)  
	

clean:
	@echo "$(YELLOW)Removing libft$(DEF_COLOR)"
	@make clean  -C $(LIBFT_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(DEF_COLOR)"
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_DIR)$(LIBFT_NAME)

re: fclean all
	@echo "$(BLUE)Cleaned and rebuilt everything for $(NAME).$(DEF_COLOR)"

# Phony targets
.PHONY: all clean fclean re
