/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:28:28 by arsenii           #+#    #+#             */
/*   Updated: 2024/09/11 09:39:46 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(int fd, t_map_data *map)
{
	int		i;
	char	*line;
	int		line_count;

	i = 0;
	line_count = map->rows + 1;
	map->map_storage = (char **)malloc(line_count * sizeof(char *));
	if (!map->map_storage)
		error_exit("Error\n", map);
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
	game->move = 1;
	game->map.rows = 0;
	game->map.cols = 0;
	game->end_game = 0;
	game->map.exit = 0;
	game->map.collectables = 0;
	game->map.map_storage = NULL;
}

void	start_game(t_game *game)
{
	int	x;
	int	y;

	game->window.mlx = mlx_init();
	game->window.win = mlx_new_window(game->window.mlx, game->map.cols * WIDTH,
			game->map.rows * HEIGHT, "SO_LONG");
	set_textures(game);
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			if (game->map.map_storage[y][x] == '1')
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->window.img.wall, x * WIDTH, y * HEIGHT);
			x++;
		}
		y++;
	}
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

	// arg_checker(argc, argv, &game.map);
	filename = argv[1];
	fd1 = open(filename, O_RDONLY);
	fd2 = open(filename, O_RDONLY);
	fd_path = open(filename, O_RDONLY);
	check_fd(fd1);
	prepare_game(&game);
	map_size(fd1, &game.map);
	read_map(fd2, &game.map);
	map_validation(&game.map);
	check_path(&game, fd_path);
	close(fd1);
	close(fd2);
	printf("Starting game!\n");
	start_game(&game);
	printf("YOU WONE!\n");
}
