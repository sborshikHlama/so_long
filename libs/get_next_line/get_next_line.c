/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:11:40 by arsenii           #+#    #+#             */
/*   Updated: 2024/07/11 18:30:14 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string = read_append(fd, string);
	if (!string)
		return (NULL);
	line = get_line(string);
	string = update_line(string);
	return (string);
}

char	*read_append(int fd, char *string)
{
	char	*tmp;
	int		bytes;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr_gnl(string, '\n') && bytes != 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[bytes] = '\0';
		string = ft_strjoin_gnl(string, tmp);
	}
	free(tmp);
	return (string);
}
