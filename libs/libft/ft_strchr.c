/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsenii <arsenii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:55:34 by aevstign          #+#    #+#             */
/*   Updated: 2024/09/08 21:10:00 by arsenii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	else
		return (NULL);
}

// The `ft_strchr` function is a custom implementation 
// of the standard C library function `strchr`.
// Here's what it does:
// 1. It takes two parameters: a constant character pointer 
// `str` and an integer `c`.
// 2. It iterates through the string `str` character by character.
// 3. For each character, it checks if it matches the character `c`.
// 4. If a match is found, it returns a pointer to that character in the string.
// 5. If the end of the string is reached without finding the 
// character, it returns `NULL`.
// 6. If the character `c` is found at the end of the string, 
// it returns a pointer to that character.