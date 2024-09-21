/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:34:13 by aevstign          #+#    #+#             */
/*   Updated: 2024/09/21 20:07:15 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(int fd, t_map_data *map)
{
	int		i;
	char	*line;
	int		line_count;
	char	*strimed_line;

	i = 0;
	line_count = map->rows + 1;
	map->map_storage = (char **)malloc(line_count * sizeof(char *));
	if (map->map_storage == NULL)
	{
		close(fd);
		error_exit("Error while reading map", map, 0);
	}
	while (i < line_count)
	{
		line = get_next_line(fd);
		map->map_storage[i] = ft_strtrim(line, "\n");
		i++;
		free(line);
	}
}

void	prepare_game(t_game *game)
{
	game->map.player = 0;
	game->move = 0;
	game->map.rows = 0;
	game->map.cols = 0;
	game->end_game = 0;
	game->map.exit = 0;
	game->map.collectables = 0;
	game->map.map_storage = NULL;
	game->map.path_map = NULL;
}

void	start_game(t_game *game)
{
	int	x;
	int	y;

	game->window.mlx = mlx_init();
	game->window.win = mlx_new_window(game->window.mlx, game->map.cols * WIDTH,
			game->map.rows * HEIGHT, "SO_LONG");
	set_textures(game);
	put_static(game);
	render_img(game);
	mlx_key_hook(game->window.win, move_key, game);
	mlx_hook(game->window.win, 17, 0, close_window, game);
	mlx_expose_hook(game->window.win, render_img, game);
	mlx_loop(game->window.mlx);
}

void	map_validation(t_map_data *map)
{
	map_checker(map);
	wall_checker(map);
	ractangle_checker(map);
}

int	main(int argc, char **argv)
{
	t_game		game;
	int			fd1;
	int			fd2;
	int			fd_path;
	char		*filename;

	arg_checker(&game.map, argc, argv);
	filename = argv[1];
	game.fd = open(filename, O_RDONLY);
	check_fd(game.fd);
	prepare_game(&game);
	map_size(game.fd, &game.map);
	close(game.fd);
	game.fd = open(filename, O_RDONLY);
	check_fd(game.fd);
	read_map(game.fd, &game.map);
	close(game.fd);
	map_validation(&game.map);
	game.fd = open(filename, O_RDONLY);
	check_path(&game, game.fd);
	close(game.fd);
	ft_putendl_fd("Starting game!", 1);
	start_game(&game);
}
