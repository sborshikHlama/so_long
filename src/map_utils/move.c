/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:26:32 by arsenii           #+#    #+#             */
/*   Updated: 2024/08/07 00:07:13 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	valid_move(t_game *game, int col, int row, int pressed_key)
{
	game->window.temp = '0';

	if (game->map.map_storage[row][col] == '1')
		return (-1);
	if (game->map.map_storage[row][col] == 'C')
		game->map.collectables--;
	if (game->map.map_storage[row][col] == 'E' && game->map.collectables > 0)
	{
		game->window.temp = 'O';
		return (1);
	}
	if (game->map.map_storage[row][col] == 'E' && game->map.collectables == 0)
	{
		return (2);
	}
	return (1);
}

void	end_game(t_game *game, int col, int row)
{
	game->map.map_storage[row][col] = 'F';
	render_img(game);
	game->end_game = 1;
}

void	ft_helpa(int n)
{
	write(1, "Step: ", 6);
	ft_putnbr_fd(n, 1);
	write(1, "\n", 1);
}

static void	moving(t_game *game, int col, int row, int pressed_key)
{
	int	valid;
	int	tcol;
	int	trow;

	tcol = game->map.player_position_y;
	trow = game->map.player_position_x;
	valid = valid_move(game, col, row, pressed_key);

	if (valid != -1)
	{
		// Очистить предыдущее место игрока

		// Переместить игрока на новую позицию
		if (game->map.map_storage[trow][tcol] == 'P')
			game->map.map_storage[trow][tcol] = (game->window.temp == 'O') ? 'E' : '0';
			
		game->map.player_position_y = col;
		game->map.player_position_x = row;
		if (valid == 2)
		{
			end_game(game, col, row);
		}
		else
		{
			game->map.map_storage[row][col] = 'P';
		}

		ft_helpa(game->move++);
		render_img(game);
	}
}

int	move_key(int keycode, t_game *game)
{
	int	col;
	int	row;

	col = game->map.player_position_y;
	row = game->map.player_position_x;

	if (keycode == A)
		col--;
	else if (keycode == W)
		row--;
	else if (keycode == S)
		row++;
	else if (keycode == D)
		col++;
	else if (keycode == ESC)
		close_window(game);

	if (game->end_game != 1)
		moving(game, col, row, keycode);
	else if (game->end_game == 1)
		close_window(game);

	return (0);
}
