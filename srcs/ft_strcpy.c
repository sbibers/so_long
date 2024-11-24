/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:55:54 by salam             #+#    #+#             */
/*   Updated: 2024/11/24 19:41:58 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strcpy(char *dest, char *src)
// copy line by line to double pointer.
{
	int	len;

	len = ft_strlen(src);
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	len = 0;
	while (src[len])
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

int	check_char(char c)
// check if the map have any wrong char.
{
	if (c != '1' && c != '0' && c != 'C' && c != 'P' && c != 'E' && c != '\n'
		&& c != 'A')
	{
		return (1);
	}
	return (0);
}
