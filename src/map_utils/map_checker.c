/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:17:24 by arsenii           #+#    #+#             */
/*   Updated: 2024/07/17 14:52:08 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	validate_char(t_map_data *map, char c, int x, int y)
{
	if (c == 'C')
		map->collectables++;
	else if (c == 'E')
		map->exit++;
	else if (c == 'P')
	{
		map->player++;
		map->player_position_x = x;
		map->player_position_y = y;
	}
	else if (c == 1 || c == 0)
		return ;
	else
		error_exit("Error: Invalid character\n", map);
}

void	map_checker(t_map_data *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			validate_char(map, map->map_storage[x][y], x, y);
			y++;
		}
		x++;
	}
	if (map->collectables == 0)
		error_exit("Error: No collectibles found", map);
	else if (map->exit == 0)
		error_exit("Error: No exit found", map);
	else if (map->exit > 1)
		error_exit("Error: map can contain only one exit", map);
	else if (map->player == 0)
		error_exit("Error: No player found", map);
	else if (map->player > 1)
		error_exit("Error: map can contain only one player", map);
}

void	wall_checker(t_map_data *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->map_storage[x])
	{
		y = 0;
		while (map->map_storage[y])
		{
			if (map->map_storage[x][0] != '1'
				|| map->map_storage[map->width - 1] != '1')
				error_exit("Error: map is not surrounded by walls", map);
			if (map->map_storage[0][y] != '1'
				|| map->map_storage[map->height - 1] != '1')
				error_exit("Error: map is not surrounded by walls", map);
			y++;
		}
		x++;
	}
}

void	ractangle_checker(t_map_data *map)
{
	int	x;
	int	y;
	int	size;

	x = 0;
	y = 0;
	size = ft_strlen(map->map_storage[0]);
	while (map->map_storage[x] != 0)
	{
		y = ft_strlen(map->map_storage[x]);
		if (y != size)
			error_exit("Error: Map is not rectangular", map);
		x++;
	}
}

void	run_map_checkers(t_map_data *map)
{
	map_checker(map);
	wall_checker(map);
	ractangle_checker(map);
}


