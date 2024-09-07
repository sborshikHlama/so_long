/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:47:48 by arsenii           #+#    #+#             */
/*   Updated: 2024/08/28 22:00:21 by arsenii          ###   ########.fr       */
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

	// if (game->window.img.wall == NULL)
	// {
	// 	printf("Ошибка: не удалось загрузить текстуру WALL из файла %s\n", WALL);
	// 	exit(1); // Завершение программы с ошибкой
	// }

	// if (game->window.img.floor == NULL)
	// {
	// 	printf("Ошибка: не удалось загрузить текстуру FLOOR из файла %s\n", GROUND);
	// 	exit(1); // Завершение программы с ошибкой
	// }
	// game->window.img->floor = mlx_xpm_file_to_image(game->window.mlx,
	// 		EXIT, &width, &height);
	// game->window.img->floor = mlx_xpm_file_to_image(game->window.mlx,
	// 		COLLECTABLE, &width, &height);
	// game->window.img->floor = mlx_xpm_file_to_image(game->window.mlx,
	// 		FLOOR, &width, &height);
}

void	put_map(int x, int y, char c, t_game *game)
{
	static int width = WIDTH;
	static int height = HEIGHT;

	if (c == '1') {
		mlx_put_image_to_window(game->window.mlx, game->window.win,
                game->window.img.wall, x * width, y * height);
		// mlx_pixel_put(game->window.mlx, game->window.win, 400, 300, 0xFFFFFF); 
	}
    else if (c == '0')
		mlx_put_image_to_window(game->window.mlx, game->window.win,
				game->window.img.floor, x * width, y * height);
		// mlx_pixel_put(game->window.mlx, game->window.win, x * width, y * height, 0xFFFFFF); 
	else if (c == 'P') {
        // Затем рисуем игрока поверх пола
        mlx_put_image_to_window(game->window.mlx, game->window.win,
                                game->window.img.player, x * width, y * height);
    }
	else if (c == 'E')
	{
		mlx_put_image_to_window(game->window.mlx, game->window.win,
                                game->window.img.floor, x * width, y * height);
        // Затем рисуем игрока поверх пола
        mlx_put_image_to_window(game->window.mlx, game->window.win,
                                game->window.img.exit, x * width, y * height);
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(game->window.mlx, game->window.win,
        						game->window.img.floor, x * width, y * height);
        mlx_put_image_to_window(game->window.mlx, game->window.win,
                                game->window.img.collectable, x * width, y * height);
	}
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
			printf("%c", game->map.map_storage[y][x]);
			put_map(x, y, game->map.map_storage[y][x], game);
			x++;
		}
		printf("\n");
		y++;
	}
	return (0);
}
