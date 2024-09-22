/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:34:41 by aevstign          #+#    #+#             */
/*   Updated: 2024/09/22 11:45:09 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map_data *map)
{
	int	i;

	i = 0;
	if (!map->map_storage)
		ft_putendl_fd("Error: map is not allocated", 1);
	while (map->map_storage[i])
	{
		free(map->map_storage[i]);
		i++;
	}
	free(map->map_storage);
}

void	error_exit(char *msg, t_map_data *map, int map_allocated)
{
	ft_putendl_fd(msg, 1);
	if (map_allocated)
		free_map(map);
	exit(1);
}

void	arg_checker(t_map_data *map, int argc, char **argv)
{
	if (argc != 2)
		error_exit("Error: invalid number of arguments", map, 0);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
	{
		error_exit("Error: invalid map format", map, 0);
	}
}

void	check_fd(int fd)
{
	if (fd < 0)
	{
		close(fd);
		ft_putendl_fd("Error: Failed to open the map file", 1);
		exit(1);
	}
}
