/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:26:32 by arsenii           #+#    #+#             */
/*   Updated: 2024/08/04 18:36:12 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_size(int fd, t_map_data *map_data)
{
	char	*line;
	int		max_width = 0;
	int		height = 0;
	int		line_length;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;

		line_length = ft_strlen(line + 1);
		if (line_length > max_width)
			max_width = line_length;

		height++;
		free(line);
	}

	// Set the map dimensions
	map_data->width = max_width; // Set to max line length
	map_data->height = height;   // Set to number of lines

	// Handle cases where the map file might be empty
	if (height == 0 || max_width == 0)
		error_exit("Error: Map file is empty or invalid\n", map_data);
}


