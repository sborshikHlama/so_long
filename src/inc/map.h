/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:31:52 by arsenii           #+#    #+#             */
/*   Updated: 2024/07/26 18:46:58 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct map_data
{
	int		height;
	int		width;
	int		collectables;
	char	**map_storage;
	int		player_position_x;
	int		player_position_y;
	int		player;
	int		exit;
	char	**map_traversable;
}	t_map_data;

void	map_size(int fd, t_map_data *map_data);
int		count_collectables(t_map_data *game);

#endif