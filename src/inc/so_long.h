/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:31:44 by arsenii           #+#    #+#             */
/*   Updated: 2024/08/06 22:59:42 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./map.h"
# include "./window.h"
# include "./errors.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "../../libs/get_next_line/get_next_line.h"
# include "../../libs/libft/libft.h"
# include "../../libs/minilibx/mlx.h"

#define W 13
#define A 0
#define S 1
#define D 2
#define ESC 53

# define WALL "./wall.xpm"
# define GROUND "./ground.xpm"
# define PLAYER "./player.xpm"
# define COLLECTABLE "./collectable.xpm"
# define EXIT_CLOSED "./exit_close.xpm"

typedef struct s_game
{
	t_map_data	map;
	t_window	window;
	int			move;
	int			end_game;
}	t_game;

void	set_textures(t_game *game);
void	put_map(int x, int y, char c, t_game *game);
int	render_img(t_game *game);

int		count_collectables(t_map_data *map);

void	traversable_test_malloc(t_game *game, int fd);

bool	test_traversable(t_map_data *map, int x, int y);

void	free_img(t_game *game);

void	free_map(t_map_data *map);

int		close_window(t_game *game);


void	end_game(t_game *game, int col, int row);

int	move_key(int keycode, t_game *game);

void	run_map_checkers(t_map_data *map);

void	run_traversable_checks(t_game *game, int fd);

#endif /* SO_LONG_H */