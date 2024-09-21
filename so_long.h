/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:46:24 by aevstign          #+#    #+#             */
/*   Updated: 2024/09/21 19:17:29 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "../libs/get_next_line/get_next_line.h"
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <stdbool.h>

// Keys for mac
// # define W 13
// # define A 0
// # define S 1
// # define D 2
// # define ESC 53

//Keys for linux
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

# define WALL "./assets/wall.xpm"
# define GROUND "./assets/ground.xpm"
# define PLAYER "./assets/player.xpm"
# define COLLECTABLE "./assets/collectable.xpm"
# define EXIT_CLOSED "./assets/exit_close.xpm"
# define PLAYER_FRONT_XPM	"./assets/front.xpm"
# define PLAYER_LEFT_XPM	"./assets/left.xpm"
# define PLAYER_RIGHT_XPM	"./assets/right.xpm"
# define PLAYER_BACK_XPM	"./assets/back.xpm"
# define EXIT_OPENED "./assets/exit_open.xpm"

typedef struct s_img
{
	void	*collectable;
	void	*player;
	void	*wall;
	void	*exit;
	void	*fin_exit;
	void	*on_exit;
	void	*floor;
	void	*exit_open;
}	t_img;

typedef struct window
{
	t_img	img;
	void	*mlx;
	void	*win;
	char	temp;
}	t_window;

typedef struct map_data
{
	int		rows;
	int		cols;
	int		collectables;
	char	**map_storage;
	int		player_position_x;
	int		player_position_y;
	int		player;
	int		exit;
	char	**path_map;
}	t_map_data;

typedef struct s_game
{
	t_map_data	map;
	t_window	window;
	int			move;
	int			end_game;
	int			fd;
}	t_game;

# define WIDTH 71
# define HEIGHT 71

void	map_size(int fd, t_map_data *map);

void	wall_checker(t_map_data *map);

void	error_exit(char *msg, t_map_data *map, int map_allocated);

void	map_checker(t_map_data *map);

void	put_static(t_game *game);

void	check_fd(int fd);

void	ractangle_checker(t_map_data *map);

void	arg_checker(t_map_data *map, int argc, char **argv);

void	set_textures(t_game *game);

void	put_map(int x, int y, char c, t_game *game);

int		render_img(t_game *game);

void	free_img(t_game *game);

void	free_map(t_map_data *map);

int		close_window(t_game *game);

void	display_step(int n);

void	check_path(t_game *game, int fd);

void	end_game(t_game *game, int col, int row);

int		move_key(int keycode, t_game *game);

void	map_validation(t_map_data *map);

#endif /* SO_LONG_H */