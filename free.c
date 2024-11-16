/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:49:38 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/16 17:38:30 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	if (vars->c && vars->win && vars->wall && vars->p && vars->em && vars->ex)
	{
		mlx_destroy_image(vars->mlx, vars->c);
		mlx_destroy_image(vars->mlx, vars->en);
		mlx_destroy_image(vars->mlx, vars->em);
		mlx_destroy_image(vars->mlx, vars->ex);
		mlx_destroy_image(vars->mlx, vars->p);
		mlx_destroy_image(vars->mlx, vars->wall);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}

int	close_window(t_vars *vars)
{
	ft_free(vars);
	ft_free_string(vars->copy_map);
	ft_free_string(vars->copy_map_2);
	exit(0);
	return (0);
}

void	error_handle(t_vars *vars)
{
	write(2, "Error\nwrong map\n", 16);
	ft_free_string(vars->map);
	ft_free_string(vars->copy_map);
	ft_free_string(vars->copy_map_2);
	exit(1);
}
