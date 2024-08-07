/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:17:24 by arsenii           #+#    #+#             */
/*   Updated: 2024/08/06 23:02:14 by arsenii          ###   ########.fr       */
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
	else if (c == '1' || c == '0') // Исправлено с числового на символьное
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
			validate_char(map, map->map_storage[y][x], x, y); // Исправлено с map->map_storage[x][y] на map->map_storage[y][x]
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
	while (x < map->height) // Используем y для проверки строк
	{
		y = 0;
		while (y < map->width)
		{
			if (map->map_storage[x][0] != '1' 
				|| map->map_storage[x][map->width - 1] != '1')
				error_exit("Error: map is not surrounded by walls", map);
			if (map->map_storage[0][y] != '1' 
				|| map->map_storage[map->height - 1][y] != '1')
				error_exit("Error: map is not surrounded by walls", map);
			y++;
		}
		x++;
	}
}

void	ractangle_checker(t_map_data *map)
{
	int	x;
	int	size;

	x = 0;
	size = ft_strlen(map->map_storage[0]);
	while (map->map_storage[x] != 0)
	{
		if (ft_strlen(map->map_storage[x]) != size)
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
