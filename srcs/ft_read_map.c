/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:19:10 by salam             #+#    #+#             */
/*   Updated: 2024/11/28 07:58:15 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	faild_alloacte(char *str)
{
	free(str);
	write(2, "Error\nMemory allocation failed\n", 31);
	exit(1);
}

static void	split_map(t_vars *vars, char *map)
{
	vars->map = ft_split(map, '\n');
	vars->copy_map = ft_split(map, '\n');
	vars->copy_map_2 = ft_split(map, '\n');
	free(map);
}

void	read_map(t_vars *vars, char *file_map)
// read map.
{
	char	*str;
	char	*map;

	map = NULL;
	vars->fd = open(file_map, O_RDONLY);
	if (vars->fd == -1)
	{
		write(2, "Error\nthis argument not a map\n", 30);
		exit(1);
	}
	while (1)
	{
		str = get_next_line(vars->fd);
		if (str == NULL)
			break ;
		map = ft_strjoin(map, str);
		if (!map)
			faild_alloacte(str);
		free(str);
	}
	if (map)
		split_map(vars, map);
	close(vars->fd);
}
