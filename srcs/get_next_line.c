/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:37:53 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/13 14:35:23 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_read_save(int fd, char *save)
{
	char	*buffer;
	int		byte_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(save);
		return (NULL);
	}
	byte_read = 1;
	while (!ft_strchr(save, '\n') && byte_read != 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

static char	*ft_line(char *save)
{
	int		i;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
	{
		free(save);
		return (NULL);
	}
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_save(char *save)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(ft_strlen(save) - i + 1);
	if (!str)
	{
		free(save);
		return (NULL);
	}
	i++;
	j = 0;
	while (save[i] != '\0')
		str[j++] = save[i++];
	str[j] = '\0';
	free(save);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_line(save);
	save = ft_save(save);
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
