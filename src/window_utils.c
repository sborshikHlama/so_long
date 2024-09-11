/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:47:48 by arsenii           #+#    #+#             */
/*   Updated: 2024/09/10 22:12:53 by arsenii          ###   ########.fr       */
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
	game->window.img.floor = mlx_xpm_file_to_image(game->window.mlx,
			GROUND, &width, &height);
	game->window.img.player = mlx_xpm_file_to_image(game->window.mlx,
			PLAYER, &width, &height);
	game->window.img.exit = mlx_xpm_file_to_image(game->window.mlx,
			EXIT_CLOSED, &width, &height);
	game->window.img.collectable = mlx_xpm_file_to_image(game->window.mlx,
			COLLECTABLE, &width, &height);
}

void	put_dinamic(int x, int y, char c, t_game *game)
{
	static int	width = WIDTH;
	static int	height = HEIGHT;

	if (c == '0' || c == 'C' || c == 'P')
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->window.img.floor, x * width, y * height);
	else if (c == 'E')
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->window.img.exit, x * width, y * height);
	if (c == 'P')
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->window.img.player, x * width, y * height);
	if (c == 'C')
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->window.img.collectable, x * width, y * height);
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
