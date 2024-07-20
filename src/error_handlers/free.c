/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:30:19 by arsenii           #+#    #+#             */
/*   Updated: 2024/07/20 10:39:44 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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



