/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:43:13 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/13 14:35:27 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *argv, t_vars *vars)
{
	int		fd;
	char	*str;
	int		count;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(1);
	count = -1;
	vars->map = (char **)malloc(MAX_LINES * sizeof(char *) + 1);
	if (vars->map == NULL)
		exit(1);
	while (++count < MAX_LINES)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		vars->map[count] = ft_strcpy(vars->map[count], str);
		if (!vars->map[count])
		{
			free(str);
			break ;
		}
	}
	vars->map[count] = NULL;
	close(fd);
}

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
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2 || argv[1][0] == '\0')
		return (perror("Inalid input"), 1);
	read_map(argv[1], &vars);
	check(&vars);
	check_sympol(&vars);
	check_wall(&vars);
	calculate(&vars);
	get_position(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.w_width, vars.w_height, "so_long");
	xpm_to_file(&vars);
	if (!vars.p || !vars.wall || !vars.c || !vars.em || !vars.en || !vars.ex)
		return (ft_free(&vars), perror("Failed to load images"), 1);
	render_map(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
