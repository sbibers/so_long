/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:38:46 by salam             #+#    #+#             */
/*   Updated: 2024/11/15 15:12:54 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_move(char **map, int x, int y)
{
	return (map[y][x] != '1');
}

int	dfs(t_vars *vars, int x, int y, int *collect)
{
	if (vars->copy_map[y][x] == 'E' && *collect == 0)
		return (1);
	if (vars->copy_map[y][x] == '1')
		return (0);
	if (vars->copy_map[y][x] == 'C')
		(*collect)--;
	vars->copy_map[y][x] = '1';
	if (is_valid_move(vars->copy_map, x + 1, y)
		&& dfs(vars, x + 1, y, collect))
		return (1);
	if (is_valid_move(vars->copy_map, x - 1, y)
		&& dfs(vars, x - 1, y, collect))
		return (1);
	if (is_valid_move(vars->copy_map, x, y + 1)
		&& dfs(vars, x, y + 1, collect))
		return (1);
	if (is_valid_move(vars->copy_map, x, y - 1)
		&& dfs(vars, x, y - 1, collect))
		return (1);
	return (0);
}

int	check_map(t_vars *vars)
{
	int	collect;
	int	i;
	int	j;

	i = -1;
	collect = 0;
	while (vars->copy_map[++i] != NULL)
	{
		j = -1;
		while (vars->copy_map[i][++j])
		{
			if (vars->copy_map[i][j] == 'C')
				collect++;
		}
	}
	dfs(vars, vars->player_x, vars->player_y, &collect);
	if (collect == 0)
		return (1);
	else
		error_handle(vars);
	return (0);
}
