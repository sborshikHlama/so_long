/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:33:47 by aevstign          #+#    #+#             */
/*   Updated: 2024/09/21 20:28:17 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_map_malloc(t_game *game, int fd)
{
	char	*line;
	int		y;
	int		i;

	i = 0;
	y = game->map.rows + 1;
	game->map.path_map = (char **)malloc(sizeof(char *) * y);
	if (!game->map.path_map)
	{
		close(fd);
		error_exit("Error: can't alloc path map", game->map.map_storage, 0);
	}
	while (i < y)
	{
		line = get_next_line(fd);
		game->map.path_map[i] = ft_strtrim(line, "\n");
		i++;
		free(line);
	}
}

bool	valid_path(t_game *game, int x, int y)
{
	static bool	exit = false;
	static int	collectables = 0;

	if (x < 0 || y < 0 || y >= game->map.rows || x >= game->map.cols)
		return (false);
	else if (game->map.path_map[y][x] == 'X')
		return (false);
	else if (game->map.path_map[y][x] == '1')
		return (false);
	else if (game->map.path_map[y][x] == 'E')
		exit = true;
	else if (game->map.path_map[y][x] == 'C')
		collectables++;
	game->map.path_map[y][x] = 'X';
	valid_path(game, x, y + 1);
	valid_path(game, x + 1, y);
	valid_path(game, x, y - 1);
	valid_path(game, x - 1, y);
	return (exit && collectables == game->map.collectables);
}

bool	passabillity(t_game *game)
{
	int		x;
	int		y;
	bool	valid;

	x = game->map.player_position_x;
	y = game->map.player_position_y;
	valid = valid_path(game, x, y);
	return (valid);
}

void	free_path_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.path_map[i])
		free(game->map.path_map[i++]);
	free(game->map.path_map);
}

void	check_path(t_game *game, int fd)
{
	path_map_malloc(game, fd);
	if (!passabillity(game))
	{
		free_path_map(game);
		close(fd);
		error_exit("Error: Impossible to pass", &game->map, 1);
	}
	free_path_map(game);
}
