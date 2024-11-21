/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:47:47 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/21 15:06:26 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	norm(t_vars *vars, int i, int j, int flag)
{
	if (vars->map[i][j] == 'P' && flag == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p, j * vars->i_wid,
			i * vars->i_hei);
	else if (vars->map[i][j] == 'P' && flag == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p_2,
			j * vars->i_wid, i * vars->i_hei);
}

static void	put_map(t_vars *vars, int i, int j, int flag)
{
	if (vars->map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, j
			* vars->i_wid, i * vars->i_hei);
	else if (vars->map[i][j] == 'P')
		norm(vars, i, j, flag);
	else if (vars->map[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->c, j * vars->i_wid,
			i * vars->i_hei);
	else if (vars->map[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->em, j * vars->i_wid,
			i * vars->i_hei);
	else if (vars->map[i][j] == 'A')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->en, j * vars->i_wid,
			i * vars->i_hei);
	else if (vars->map[i][j] == 'E')
	{
		if (check_exit(vars->map))
			mlx_put_image_to_window(vars->mlx, vars->win, vars->ex, j
				* vars->i_wid, i * vars->i_hei);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->em, j
				* vars->i_wid, i * vars->i_hei);
	}
}

void	render_map(t_vars *vars, int flag)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map[++i] != NULL)
	{
		j = -1;
		while (vars->map[i][++j] != '\0' && vars->map[i][j] != '\n')
			put_map(vars, i, j, flag);
	}
}
