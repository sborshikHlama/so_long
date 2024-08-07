/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:26:17 by arsenii           #+#    #+#             */
/*   Updated: 2024/08/04 16:15:21 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# define WIDTH 71
# define HEIGHT 71
// # define PLAYER "./textures/player.xpm"
// # define COLLECTABLE "./textures/little.xpm"
// # define EXIT "./textures/exit.xpm"
// # define FIN_EXIT "./textures/fin_exit.xpm"
// # define ON_EXIT "./textures/on_exit.xpm"

typedef struct s_img
{
	void	*collectable;
	void	*player;
	void	*wall;
	void	*exit;
	void	*fin_exit;
	void	*on_exit;
	void	*floor;
}	t_img;

typedef struct window
{
	t_img	img;
	void	*mlx;
	void	*win;
	char	temp;
}	t_window;


#endif