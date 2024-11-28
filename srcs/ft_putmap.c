/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:47:47 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/24 19:27:12 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_move(t_vars *vars, int i, int j, int flag)
{
	if (flag == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p, j * vars->i_wid,
			i * vars->i_hei);
	else if (flag == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p_2,
			j * vars->i_wid, i * vars->i_hei);
}

static void	put_map(t_vars *vars, int i, int j, int flag)
// put all the images in the correct place.
{
	if (vars->map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, j
			* vars->i_wid, i * vars->i_hei);
	else if (vars->map[i][j] == 'P')
		player_move(vars, i, j, flag);
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
		if (number_of_collect(vars->map))
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
		while (vars->map[i][++j] != '\0')
			put_map(vars, i, j, flag);
	}
}
