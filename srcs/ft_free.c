/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:49:38 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/23 11:11:39 by sbibers          ###   ########.fr       */
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
	if (vars->p_2)
		mlx_destroy_image(vars->mlx, vars->p_2);
	if (vars->c)
		mlx_destroy_image(vars->mlx, vars->c);
	if (vars->en)
		mlx_destroy_image(vars->mlx, vars->en);
	if (vars->em)
		mlx_destroy_image(vars->mlx, vars->em);
	if (vars->ex)
		mlx_destroy_image(vars->mlx, vars->ex);
	if (vars->p)
		mlx_destroy_image(vars->mlx, vars->p);
	if (vars->wall)
		mlx_destroy_image(vars->mlx, vars->wall);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}

int	close_window(t_vars *vars)
{
	ft_free_string(vars->map);
	ft_free_string(vars->copy_map);
	ft_free_string(vars->copy_map_2);
	ft_free(vars);
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

void	free_win(t_vars *vars)
{
	write(2, "Error\ncan not initialization\n", 29);
	ft_free_string(vars->map);
	ft_free_string(vars->copy_map);
	ft_free_string(vars->copy_map_2);
	ft_free(vars);
	exit(1);
}
