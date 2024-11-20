/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:43:13 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/20 19:35:00 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[0][i] != '\n')
		i++;
	j = 0;
	while (vars->map[j] != NULL)
		j++;
	vars->w_height = j * 60;
	vars->w_width = i * 60;
	get_position(vars);
	check_map(vars);
}

void	get_position(t_vars *vars)
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
			}
			j++;
		}
		i++;
	}
}

static void	xpm_to_file(t_vars *vars)
{
	vars->p = mlx_xpm_file_to_image(vars->mlx, "./.xpm/p.xpm", &vars->i_wid,
			&vars->i_hei);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "./.xpm/w.xpm", &vars->i_wid,
			&vars->i_hei);
	vars->c = mlx_xpm_file_to_image(vars->mlx, "./.xpm/collec.xpm",
			&vars->i_wid, &vars->i_hei);
	vars->em = mlx_xpm_file_to_image(vars->mlx, "./.xpm/em.xpm", &vars->i_hei,
			&vars->i_hei);
	vars->ex = mlx_xpm_file_to_image(vars->mlx, "./.xpm/ex.xpm", &vars->i_hei,
			&vars->i_wid);
	vars->en = mlx_xpm_file_to_image(vars->mlx, "./.xpm/en.xpm", &vars->i_hei,
			&vars->i_wid);
	if (!vars->en || !vars->p || !vars->wall || !vars->c || !vars->em
		|| !vars->ex)
	{
		ft_free(vars);
		ft_free_string(vars->map);
		ft_free_string(vars->copy_map);
		ft_free_string(vars->copy_map_2);
		write(2, "Error\nFailed to load images\n", 28);
		exit(1);
	}
}

static void	check_name(char *name)
{
	char	*ber;
	int		i;
	int		j;

	if (ft_strlen(name) < 4)
	{
		write(2, "Error\nmap must name .ber\n", 25);
		exit(1);
	}
	i = 0;
	j = 3;
	ber = ".ber";
	while (name[i])
		i++;
	while (j >= 0)
	{
		if (ber[j--] != name[--i])
		{
			write(2, "Error\nmap must name .ber\n", 25);
			exit(1);
		}
	}
	check_empty(name);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc == 2)
	{
		check_name(argv[1]);
		read_map(&vars, argv[1]);
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
		render_map(&vars);
		mlx_key_hook(vars.win, key_hook, &vars);
		mlx_hook(vars.win, 17, 0, close_window, &vars);
		mlx_loop(vars.mlx);
	}
	else
		write(2, "Error\n./so_long map.ber\n", 24);
	return (0);
}
