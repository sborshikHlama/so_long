/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:33:29 by aevstign          #+#    #+#             */
/*   Updated: 2024/09/22 12:19:43 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_textures(t_game *game)
{
	int	width;
	int	height;

	width = 100;
	height = 100;
	game->window.img.wall = mlx_xpm_file_to_image(game->window.mlx,
			WALL, &width, &height);
	check_texture(game, game->window.img.wall);
	game->window.img.floor = mlx_xpm_file_to_image(game->window.mlx,
			GROUND, &width, &height);
	check_texture(game, game->window.img.floor);
	game->window.img.player = mlx_xpm_file_to_image(game->window.mlx,
			PLAYER, &width, &height);
	check_texture(game, game->window.img.player);
	game->window.img.exit = mlx_xpm_file_to_image(game->window.mlx,
			EXIT_CLOSED, &width, &height);
	check_texture(game, game->window.img.exit);
	game->window.img.collectable = mlx_xpm_file_to_image(game->window.mlx,
			COLLECTABLE, &width, &height);
	check_texture(game, game->window.img.collectable);
	game->window.img.exit_open = mlx_xpm_file_to_image(game->window.mlx,
			EXIT_OPENED, &width, &height);
	check_texture(game, game->window.img.exit_open);
}

void	check_texture(t_game *game, t_img *texture)
{
	if (!texture)
	{
		ft_putendl_fd("Error: can't set textures", 1);
		close_window(game);
	}
}

void	put_static(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			if (game->map.map_storage[y][x] == '1')
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->window.img.wall, x * WIDTH, y * HEIGHT);
			else if (game->map.map_storage[y][x] == 'E')
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->window.img.exit, x * WIDTH, y * HEIGHT);
			else
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->window.img.floor, x * WIDTH, y * HEIGHT);
			x++;
		}
		y++;
	}
}

void	put_dinamic(int x, int y, char c, t_game *game)
{
	if (c == 'E' && game->map.collectables == 0)
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->window.img.exit_open, x * WIDTH, y * HEIGHT);
	if (c == 'P')
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->window.img.player, x * WIDTH, y * HEIGHT);
	if (c == 'C')
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->window.img.collectable, x * WIDTH, y * HEIGHT);
}

int	render_img(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			put_dinamic(x, y, game->map.map_storage[y][x], game);
			x++;
		}
		y++;
	}
	return (0);
}
