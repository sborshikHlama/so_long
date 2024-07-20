/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:31:44 by arsenii           #+#    #+#             */
/*   Updated: 2024/07/18 22:48:46 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./map.h"
# include "./window.h"
# include "./errors.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include ".././libs/get_next_line/get_next_line.h"
# include ".././libs/libft/libft.h"

typedef struct s_game
{
	t_map_data	map;
	t_window	window;
	int			move;
	int			end_game;
}	t_game;


#endif /* SO_LONG_H */