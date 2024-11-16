/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:56:56 by salam             #+#    #+#             */
/*   Updated: 2024/11/16 17:30:22 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_vars *vars, int x, int y)
{
	if (x < 0 || y < 0 || vars->copy_map[y][x] == '1'
		|| vars->copy_map[y][x] == '\0' || vars->copy_map[y][x] == '\n'
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

int	flood_fill_exit(t_vars *vars, int x, int y)
{
	if (x < 0 || y < 0 || vars->copy_map_2[y][x] == '1'
		|| vars->copy_map_2[y][x] == '\0' || vars->copy_map_2[y][x] == '\n'
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
	while (vars->copy_map_2[++i])
	{
		j = -1;
		while (vars->copy_map_2[i][++j])
		{
			if (vars->map[i][j] == 'C')
				vars->count_collect++;
		}
	}
	flood_fill(vars, vars->player_x, vars->player_y);
	if (flood_fill_exit(vars, vars->player_x, vars->player_y) == 1
		&& vars->count_collect == 0)
		return (1);
	else
	{
		error_handle(vars);
		return (0);
	}
}
