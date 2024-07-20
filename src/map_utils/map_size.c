/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:26:32 by arsenii           #+#    #+#             */
/*   Updated: 2024/07/20 10:39:44 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_size(int fd, t_map_data *map_data)
{
	char	c;
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (1)
	{
		c = get_next_line(fd);

		if (!c)
			break ;
		y = ft_strlen(c) - 1;
		x++;
		free(c);
	}
	if (x == 0)
	{

	}
	map_data->width = x;
	map_data->height = y;
}

