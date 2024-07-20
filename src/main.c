/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:28:28 by arsenii           #+#    #+#             */
/*   Updated: 2024/07/18 22:28:23 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

void	read_map(int fd, t_map_data *map)
{
	int		i;
	char	*line;
	int		line_count;

	line_count = map->width + 1;
	map->map_storage = (char **)malloc(line_count * sizeof(char *));
	if (!map->map_storage)
		exit_game("Error\n", map->width);
	while (i < line_count)
	{
		line = get_next_line(fd);
		map->map_storage[i] = ft_strtrim(line, '\n');
		i++;
		free(line);
	}
}

void	prepare_game(t_game *game)
{
	game->map.player_position_x = 0;
	game->map.player_position_y = 0;
	game->map.player = 0;
	game->move = 1;
	game->map.height = 0;
	game->map.width = 0;
	game->end_game = 0;
	game->map.exit = 0;
}

int	main(int argc, char **argv)
{
	t_game		game;
	int			fd;
	char		*filename;

	filename = argv[1];
	fd = open(filename, O_RDONLY);
	check_fd(fd);
	prepare_game(&game);
	map_size(fd, &game.map);
	game.map.collectables = count_collectables(&game);
	read_map(fd, &game.map);

	close(fd);
}

