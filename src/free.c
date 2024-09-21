/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:34:33 by aevstign          #+#    #+#             */
/*   Updated: 2024/09/21 21:00:17 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img(t_game *game)
{
	if (game->window.img.exit_open)
		mlx_destroy_image(game->window.mlx, game->window.img.exit_open);
	if (game->window.img.collectable)
		mlx_destroy_image(game->window.mlx, game->window.img.collectable);
	if (game->window.img.player)
		mlx_destroy_image(game->window.mlx, game->window.img.player);
	if (game->window.img.floor)
		mlx_destroy_image(game->window.mlx, game->window.img.floor);
	if (game->window.img.wall)
		mlx_destroy_image(game->window.mlx, game->window.img.wall);
	if (game->window.img.exit)
		mlx_destroy_image(game->window.mlx, game->window.img.exit);
	mlx_destroy_display(game->window.mlx);
	free_map(&game->map);
	free(game->window.mlx);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->window.mlx, game->window.win);
	free_img(game);
	exit(0);
}
