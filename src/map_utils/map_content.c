/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:11:00 by arsenii           #+#    #+#             */
/*   Updated: 2024/07/18 22:48:55 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	count_collectables(t_map_data *map)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if (map->map_storage[x][y] == 'C')
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

void	traversable_test_malloc(t_game *game, int fd)
{
	int		i;
	char	*line;
	int		x;

	i = 0;
	x = game->map.width + 1;
	game->map.map_traversable = (char **)malloc(sizeof(char *) * x);
	if (!game->map.map_traversable)
		free_window(game);
}

bool	traversable(t_map_data *map, int x, int y)
{
	static bool	exit = false;
	static int	collectables = 0;

	if (x < 0 || y < 0 || x >= map->width || y <= map->height)
		return (false);
	else if (map->map_traversable[x][y] == 'X')
		return (false);
	else if (map->map_traversable[x][y] == '1')
		return (false);
	else if (map->map_traversable[x][y] == 'E')
		return (false);
	if (map->map_traversable[x][y] == 'C')
		collectables++;
	map->map_traversable[x][y] = 'X';
	test_traversable(map, x + 1, y);
	test_traversable(map, x, y + 1);
	test_traversable(map, x - 1, y);
	test_traversable(map, x, y - 1);
	return (collectables == map->collectables && exit);
}

int	check_traversable(t_map_data *map)
{
	int		x;
	int		y;
	bool	valid;

	x = map->player_position_x;
	y = map->player_position_y;
	valid = traversable(map, x, y);
	return (valid);
}

void	run_traversable_checks(t_game *game, int fd)
{
	traversable_test_malloc(game, fd);
	free_map_traversable(&game->map);
	if (!check_traversable(&game->map))
	{
		close(fd);
		error_exit("Error: Impossible to traverse the map", &game->map);
	}
}
