/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:46:20 by arsenii           #+#    #+#             */
/*   Updated: 2024/08/28 21:49:17 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map_data *map)
{
	int	i;

	i = 0;
	while (map->map_storage[i])
	{
		free(map->map_storage[i]);
		i++;
	}
	free(map->map_storage);
}

void	error_exit(char *msg, t_map_data *map)
{

	ft_putendl_fd(msg, 1);
	ft_putendl_fd("\n", 1);
	if (map->allocated)
		free_map(map);
	exit(0);
}

void	arg_checker(t_map_data *map, int argc, char **argv)
{
	if (argc < 2)
		error_exit("Error: Invalid number of arguments", map);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		error_exit("Error: Invalid map file format", map);
}

void	check_fd(int fd)
{
	if (fd < 0)
	{
		ft_putendl_fd("Error: Failed to open the map file", 1);
		exit(0);
	}
}
