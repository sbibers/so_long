/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:52:46 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/20 20:29:23 by salam            ###   ########.fr       */
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

static void	put_str(char *move_str, t_vars *vars)
{
	if (move_str)
	{
		mlx_string_put(vars->mlx, vars->win, 50, 50, 0xFFFFFF, "Moves: ");
		mlx_string_put(vars->mlx, vars->win, 90, 50, 0xFFFFFF, move_str);
		free(move_str);
	}
	else
	{
		ft_free(vars);
		ft_free_string(vars->map);
		ft_free_string(vars->copy_map);
		ft_free_string(vars->copy_map_2);
		write(2, "Error\nmalloc itoa\n", 18);
		exit(1);
	}
}

int	clear_draw(t_vars *vars, int new_x, int new_y)
{
	static int	move_count;
	char		*move_str;

	if (vars->map[new_y][new_x] == 'C' || vars->map[new_y][new_x] == '0')
		move_count++;
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
		move_str = ft_itoa(move_count);
		put_str(move_str, vars);
	}
	return (0);
}
