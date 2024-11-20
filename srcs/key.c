/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:52:46 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/19 20:22:06 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	int	new_x;
	int	new_y;

	new_x = vars->player_x;
	new_y = vars->player_y;
	if (keycode == XK_w)
		new_y -= 1;
	else if (keycode == XK_s)
		new_y += 1;
	else if (keycode == XK_a)
		new_x -= 1;
	else if (keycode == XK_d)
		new_x += 1;
	else if (keycode == XK_Escape)
		close_window(vars);
	if (vars->map[new_y][new_x] != '1')
		clear_draw(vars, new_x, new_y);
	return (0);
}

int	check_exit(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	clear_draw(t_vars *vars, int new_x, int new_y)
{
	static int	i;

	if (vars->map[new_y][new_x] == 'C' || vars->map[new_y][new_x] == '0')
	{
		write(1, "move: ", 6);
		putnbr(++i);
		write(1, "\n", 1);
	}
	if (vars->map[new_y][new_x] == 'C')
		vars->map[new_y][new_x] = '0';
	else if ((vars->map[new_y][new_x] == 'E' && check_exit(vars->map) == 1)
			|| vars->map[new_y][new_x] == 'A')
		close_window(vars);
	if (vars->map[new_y][new_x] != 'E')
	{
		vars->map[vars->player_y][vars->player_x] = '0';
		vars->player_x = new_x;
		vars->player_y = new_y;
		vars->map[vars->player_y][vars->player_x] = 'P';
		mlx_clear_window(vars->mlx, vars->win);
		render_map(vars);
	}
	return (0);
}
