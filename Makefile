
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

MINILIBX_DIR = libs/minilibx-linux
MINILIBX     = $(MINILIBX_DIR)libmlx.a
MLXFLAGS      = -L$(MINILIBX_DIR) -lmlx -I$(MINILIBX_DIR) -lXext -lX11

NAME          = so_long
CC            = cc
FLAGS         = -Wall -Werror -Wextra -g

SRC           = ./src/main.c \
				./src/map_utils.c \
				./src/path.c \
				./src/move.c \
				./src/error_handlers.c \
				./src/free.c \
				./src/window_utils.c \
				./libs/get_next_line/get_next_line.c \
				./libs/get_next_line/get_next_line_utils.c

OBJ           = $(SRC:.c=.o)

# Targets
all: $(LIBFT) $(MINILIBX) $(NAME)

$(LIBFT):
	@echo "$(MAGENTA)Compiling libft...$(DEF_COLOR)"
	@$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	@echo "$(MAGENTA)Compiling minilibx...$(DEF_COLOR)"
	@$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	@echo "$(GREEN)Compiling $(NAME)...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS) -L$(LIBFT_DIR) -lft

%.o: %.c
	@echo "$(BLUE)Compiling $<...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(DEF_COLOR)"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@$(RM) $(OBJ)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(DEF_COLOR)"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@$(RM) $(MINILIBX)

re: fclean all

.PHONY: all clean fclean re