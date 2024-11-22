/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:56:56 by salam             #+#    #+#             */
/*   Updated: 2024/11/22 13:44:30 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(t_vars *vars, int x, int y)
{
	if (x < 0 || y < 0 || vars->copy_map[y][x] == '1'
		|| vars->copy_map[y][x] == '\0' || vars->copy_map[y][x] == 'E'
		|| vars->copy_map[y][x] == 'V' || vars->copy_map[y][x] == 'A')
		return ;
	if (vars->copy_map[y][x] == 'C')
		vars->count_collect--;
	else if (vars->copy_map[y][x] == 'E' && vars->count_collect == 0)
		return ;
	vars->copy_map[y][x] = 'V';
	flood_fill(vars, x + 1, y);
	flood_fill(vars, x - 1, y);
	flood_fill(vars, x, y - 1);
	flood_fill(vars, x, y + 1);
}

static int	flood_fill_exit(t_vars *vars, int x, int y)
{
	if (x < 0 || y < 0 || vars->copy_map_2[y][x] == '1'
		|| vars->copy_map_2[y][x] == '\0'
		|| vars->copy_map_2[y][x] == 'V' || vars->copy_map_2[y][x] == 'A')
		return (0);
	if (vars->copy_map_2[y][x] == 'E')
		return (1);
	vars->copy_map_2[y][x] = 'V';
	if (flood_fill_exit(vars, x + 1, y))
		return (1);
	if (flood_fill_exit(vars, x - 1, y))
		return (1);
	if (flood_fill_exit(vars, x, y + 1))
		return (1);
	if (flood_fill_exit(vars, x, y - 1))
		return (1);
	return (0);
}

int	check_map(t_vars *vars)
{
	int	i;
	int	j;

	vars->count_collect = 0;
	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == 'C')
				vars->count_collect++;
		}
	}
	flood_fill(vars, vars->player_x, vars->player_y);
	if (flood_fill_exit(vars, vars->player_x, vars->player_y)
		&& vars->count_collect == 0)
		return (1);
	else
	{
		error_handle(vars);
		return (0);
	}
}

void	check_empty(char *map)
{
	int		fd;
	char	buff[1];
	int		byte_read;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nno such file or no permission to read\n", 44);
		exit(1);
	}
	byte_read = read(fd, buff, 1);
	close(fd);
	if (byte_read == 0)
	{
		write(2, "Error\nempty map\n", 16);
		exit(1);
	}
}
