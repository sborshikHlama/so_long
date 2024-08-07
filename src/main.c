/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:28:28 by arsenii           #+#    #+#             */
/*   Updated: 2024/08/06 23:02:07 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

void	read_map(int fd, t_map_data *map)
{
	int		i;
	char	*line;
	int		line_count;

	i = 0;
	line_count = map->width + 1;
	map->map_storage = (char **)malloc(line_count * sizeof(char *));
	if (!map->map_storage)
		error_exit("Error\n", map);
	while (i < line_count)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		map->map_storage[i] = ft_strtrim(line, "\n");
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

void	start_game(t_game *game)
{
	game->window.mlx = mlx_init();
	game->window.win = mlx_new_window(game->window.mlx, game->map.width * WIDTH,
			game->map.height * HEIGHT, "SO_LONG");
	set_textures(game);
	render_img(game);
	mlx_key_hook(game->window.win, move_key, game);
	mlx_hook(game->window.win, 17, 0, close_window, game);
	mlx_expose_hook(game->window.win, render_img, game);
	mlx_loop(game->window.mlx);
}

int	main(int argc, char **argv)
{
	t_game		game;
	int			fd1;
	int			fd2;
	char		*filename;

	filename = argv[1];
	fd1 = open(filename, O_RDONLY);
	// check_fd(fd);
	prepare_game(&game);
	game.map.collectables = count_collectables(&game.map);
	map_size(fd1, &game.map);
	fd2 = open(filename, O_RDONLY);
	read_map(fd2, &game.map);
	run_map_checkers(&game.map);
	// run_traversable_checks(&game, fd2);
	close(fd1);
	close(fd2);
	start_game(&game);
}

