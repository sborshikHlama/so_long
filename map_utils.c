/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:34:21 by aevstign          #+#    #+#             */
/*   Updated: 2024/09/21 19:43:33 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(int fd, t_map_data *map)
{
	char	*line;
	int		max_width;
	int		height;
	int		line_length;

	max_width = 0;
	height = 0;
	line_length = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			break ;
		}
		line_length = ft_strlen(line + 1);
		if (line_length > max_width)
			max_width = line_length;
		height++;
		free(line);
	}
	map->cols = max_width;
	map->rows = height;
}

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
	else if (c == '1' || c == '0')
		return ;
	else
		error_exit("Error: invalid character", map, 1);
}

void	map_checker(t_map_data *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			validate_char(map, map->map_storage[y][x], x, y);
			x++;
		}
		y++;
	}
	if (map->collectables == 0)
		error_exit("Error: no collectables found", map, 1);
	else if (map->exit == 0)
		error_exit("Error: no exit", map, 1);
	else if (map->exit > 1)
		error_exit("Error: more than one exit", map, 1);
	else if (map->player == 0)
		error_exit("Error: no player found", map, 1);
	else if (map->player > 1)
		error_exit("Error: more than one player found", map, 1);
}

void	wall_checker(t_map_data *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->rows)
	{
		y = 0;
		while (y < map->cols)
		{
			if (map->map_storage[x][0] != '1'
				|| map->map_storage[x][map->cols - 1] != '1')
				error_exit("Error: map is not surrounded by walls", map, 1);
			if (map->map_storage[0][y] != '1'
				|| map->map_storage[map->rows - 1][y] != '1')
				error_exit("Error: map is not surrounded by walls", map, 1);
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
	while (map->map_storage[x])
	{
		if (ft_strlen(map->map_storage[x]) != size)
			error_exit("Error: map is not rectangular", map, 1);
		x++;
	}
}
