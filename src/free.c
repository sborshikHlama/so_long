/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:30:19 by arsenii           #+#    #+#             */
/*   Updated: 2024/08/28 21:37:02 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_traversable(char **map_traversable)
{
	int	i;

	if (map_traversable)
	{
		i = 0;
		while (map_traversable[i])
		{
			free(map_traversable[i]);
			i++;
		}
		free(map_traversable);
	}
}

void	free_img(t_game *game)
{
	// mlx_destroy_image(game->window.mlx, game->window.img.exit);
	// if (game->img.collectible)
	// 	mlx_destroy_image(game->mlx, game->img.collectible);
	// if (game->img.player)
	// 	mlx_destroy_image(game->mlx, game->img.player);
	if (game->window.img.floor)
		mlx_destroy_image(game->window.mlx, game->window.img.floor);
	if (game->window.img.wall)
		mlx_destroy_image(game->window.mlx, game->window.img.wall);
	// if (game->img.on_exit)
	// 	mlx_destroy_image(game->mlx, game->img.on_exit);
	// if (game->img.fin_exit)
	// 	mlx_destroy_image(game->mlx, game->img.fin_exit);
	free_map(&game->map);
	free(game->window.mlx);
	exit(0);
}


int	close_window(t_game *game)
{
	mlx_destroy_window(game->window.mlx, game->window.win);
	free_img(game);
  exit (0); 
}

