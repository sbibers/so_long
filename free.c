/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:49:38 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/13 14:35:20 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_string(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	ft_free(t_vars *vars)
{
	int	i;

	i = -1;
	while (vars->map[++i])
		free(vars->map[i]);
	free(vars->map);
	if (vars->c && vars->win && vars->wall && vars->p && vars->em && vars->ex)
	{
		mlx_destroy_image(vars->mlx, vars->c);
		mlx_destroy_image(vars->mlx, vars->em);
		mlx_destroy_image(vars->mlx, vars->ex);
		mlx_destroy_image(vars->mlx, vars->p);
		mlx_destroy_image(vars->mlx, vars->wall);
		mlx_destroy_image(vars->mlx, vars->en);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}

int	close_window(t_vars *vars)
{
	ft_free(vars);
	exit(0);
	return (0);
}
