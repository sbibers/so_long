/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:43:13 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/16 12:30:01 by salam            ###   ########.fr       */
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

void	xpm_to_file(t_vars *vars)
{
	vars->p = mlx_xpm_file_to_image(vars->mlx, "p.xpm", &vars->i_wid,
			&vars->i_hei);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "w.xpm", &vars->i_wid,
			&vars->i_hei);
	vars->c = mlx_xpm_file_to_image(vars->mlx, "collec.xpm", &vars->i_wid,
			&vars->i_hei);
	vars->em = mlx_xpm_file_to_image(vars->mlx, "em.xpm", &vars->i_hei,
			&vars->i_hei);
	vars->ex = mlx_xpm_file_to_image(vars->mlx, "ex.xpm", &vars->i_hei,
			&vars->i_wid);
	vars->en = mlx_xpm_file_to_image(vars->mlx, "en.xpm", &vars->i_hei,
			&vars->i_wid);
	if (!vars->en || !vars->p || !vars->wall || !vars->c || !vars->em
		|| !vars->ex)
	{
		ft_free(vars);
		ft_free_string(vars->copy_map);
		ft_free_string(vars->copy_map_2);
		write(2, "Error\nFailed to load images\n", 28);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	init(&vars);
	vars.fd = open(argv[1], O_RDONLY);
	if (argc != 2 || argv[1][0] == '\0' || vars.fd == -1)
	{
		write(2, "Error\n./so_long map.ber\n", 24);
		return (1);
	}
	read_map(&vars);
	check(&vars);
	check_sympol(&vars);
	check_wall(&vars);
	calculate(&vars);
	get_position(&vars);
	vars.mlx = mlx_init();
	xpm_to_file(&vars);
	check_map(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.w_width, vars.w_height, "so_long");
	render_map(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
