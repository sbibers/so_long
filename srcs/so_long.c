/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:43:13 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/28 07:48:08 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_position(t_vars *vars)
// find the position of the player.
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P')
			{
				vars->player_x = j;
				vars->player_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

static void	calculate(t_vars *vars)
// calculate the width and height to know size of the window.
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[0][i] != '\0')
		i++;
	j = 0;
	while (vars->map[j] != NULL)
		j++;
	vars->w_height = j * 60;
	vars->w_width = i * 60;
}

static void	xpm_to_file(t_vars *vars)
// convert .xpm file to image.
{
	vars->p = mlx_xpm_file_to_image(vars->mlx, "./images/p.xpm", &vars->i_wid,
			&vars->i_hei);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "./images/w.xpm",
			&vars->i_wid, &vars->i_hei);
	vars->c = mlx_xpm_file_to_image(vars->mlx, "./images/collec.xpm",
			&vars->i_wid, &vars->i_hei);
	vars->em = mlx_xpm_file_to_image(vars->mlx, "./images/em.xpm", &vars->i_hei,
			&vars->i_hei);
	vars->ex = mlx_xpm_file_to_image(vars->mlx, "./images/ex.xpm", &vars->i_hei,
			&vars->i_wid);
	vars->en = mlx_xpm_file_to_image(vars->mlx, "./images/en.xpm", &vars->i_hei,
			&vars->i_wid);
	vars->p_2 = mlx_xpm_file_to_image(vars->mlx, "./images/p_2.xpm",
			&vars->i_hei, &vars->i_wid);
	if (!vars->en || !vars->p || !vars->wall || !vars->c || !vars->em
		|| !vars->ex || !vars->p_2)
	{
		ft_free(vars);
		ft_free_string(vars->map);
		ft_free_string(vars->copy_map);
		ft_free_string(vars->copy_map_2);
		write(2, "Error\nFailed to load images\n", 28);
		exit(1);
	}
}

static void	check(t_vars *vars, char *file_name)
// read the map and check it.
{
	check_name(file_name);
	check_empty(file_name);
	read_map(vars, file_name);
	check_size(vars);
	check_sympol(vars);
	check_wall(vars);
	calculate(vars);
	get_position(vars);
	check_path(vars);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc == 2)
	{
		vars.move_count = 0;
		check(&vars, argv[1]);
		vars.mlx = mlx_init();
		if (vars.mlx == NULL)
		{
			free_win(&vars);
			return (1);
		}
		xpm_to_file(&vars);
		vars.win = mlx_new_window(vars.mlx, vars.w_width, vars.w_height,
				"so_long");
		if (vars.win == NULL)
			free_win(&vars);
		render_map(&vars, 0);
		mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
		mlx_hook(vars.win, 17, 0, close_window, &vars);
		mlx_loop(vars.mlx);
	}
	else
		write(2, "Error\n./so_long map.ber\n", 24);
	return (0);
}
