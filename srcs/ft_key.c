/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:52:46 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/24 19:41:36 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	number_of_collect(char **str)
// calculate number of collectible.
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

static void	put_number_of_movement(char *move_str, t_vars *vars, int move_count)
// put the number of movement in window and shell.
{
	if (move_str == NULL)
	{
		ft_free(vars);
		ft_free_string(vars->map);
		ft_free_string(vars->copy_map);
		ft_free_string(vars->copy_map_2);
		write(2, "Error\nwrong allocate ft_itoa\n", 29);
		exit(1);
	}
	mlx_string_put(vars->mlx, vars->win, 50, 50, 0xFFFFFF, "Moves: ");
	mlx_string_put(vars->mlx, vars->win, 90, 50, 0xFFFFFF, move_str);
	write(1, "Move : ", 7);
	putnbr(move_count);
	write(1, "\n", 1);
	free(move_str);
}

static int	clear_draw(t_vars *vars, int new_x, int new_y, int flag)
// convert the position of player.
{
	char		*move_str;

	if (vars->map[new_y][new_x] == 'C' || vars->map[new_y][new_x] == '0')
		vars->move_count++;
	else if ((vars->map[new_y][new_x] == 'E'
		&& number_of_collect(vars->map) == 1) || vars->map[new_y][new_x] == 'A')
	{
		if (vars->map[new_y][new_x] == 'A')
			write(1, "Losser :(\n", 10);
		else
			write(1, "Winner :)\n", 10);
		close_window(vars);
	}
	if (vars->map[new_y][new_x] != 'E')
	{
		vars->map[vars->player_y][vars->player_x] = '0';
		vars->player_x = new_x;
		vars->player_y = new_y;
		vars->map[vars->player_y][vars->player_x] = 'P';
		mlx_clear_window(vars->mlx, vars->win);
		render_map(vars, flag);
		move_str = ft_itoa(vars->move_count);
		put_number_of_movement(move_str, vars, vars->move_count);
	}
	return (0);
}

static int	update_position(int keycode, int *new_x, int *new_y, int *flag)
// find the new position of player.
{
	if (keycode == XK_w)
		(*new_y) -= 1;
	else if (keycode == XK_s)
		(*new_y) += 1;
	else if (keycode == XK_a)
	{
		*flag = 1;
		(*new_x) -= 1;
	}
	else if (keycode == XK_d)
	{
		*flag = 0;
		(*new_x) += 1;
	}
	else
		return (0);
	return (1);
}

int	key_hook(int keycode, t_vars *vars)
{
	int	new_x;
	int	new_y;
	int	flag;

	flag = 1;
	new_x = vars->player_x;
	new_y = vars->player_y;
	if (keycode == XK_Escape)
	{
		write(1, "Complete the game -_-\n", 22);
		close_window(vars);
		return (0);
	}
	if (!update_position(keycode, &new_x, &new_y, &flag))
		return (0);
	if (vars->map[new_y][new_x] != '1')
		clear_draw(vars, new_x, new_y, flag);
	return (0);
}
