/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:33:57 by aevstign          #+#    #+#             */
/*   Updated: 2024/09/11 16:34:00 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_move(t_game *game, int row, int col, int pressed_key)
{
	game->window.temp = '0';
	if (game->map.map_storage[row][col] == '1')
		return (-1);
	if (game->map.map_storage[row][col] == 'C')
		game->map.collectables--;
	if (game->map.map_storage[row][col] == 'E' && game->map.collectables > 0)
		return (-1);
	if (game->map.map_storage[row][col] == 'E' && game->map.collectables == 0)
		return (2);
	if (pressed_key != W && pressed_key != A
		&& pressed_key != S && pressed_key != D)
		return (-1);
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

static void	moving(t_game *game, int row, int col, int pressed_key)
{
	int	valid;
	int	old_row;
	int	old_col;

	old_row = game->map.player_position_y;
	old_col = game->map.player_position_x;
	(void)pressed_key;
	valid = valid_move(game, row, col, pressed_key);
	if (valid != -1)
	{
		game->map.player_position_y = row;
		game->map.player_position_x = col;
		game->map.map_storage[row][col] = 'P';
		game->map.map_storage[old_row][old_col] = '0';
		game->move++;
		render_img(game);
		if (valid == 2)
			close_window(game);
	}
}

int	move_key(int keycode, t_game *game)
{
	int	col;
	int	row;

	col = game->map.player_position_x;
	row = game->map.player_position_y;
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
	moving(game, row, col, keycode);
	return (0);
}
