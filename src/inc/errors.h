/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:53:17 by arsenii           #+#    #+#             */
/*   Updated: 2024/07/31 19:01:00 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "../inc/map.h"

void	check_fd(int fd);

void	arg_checker(t_map_data *map, int argc, char **argv);

void	error_exit(char *msg, t_map_data *map);

void	free_map_traversable(char **map_traversable);

#endif