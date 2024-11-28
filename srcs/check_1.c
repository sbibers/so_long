/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:52:01 by salam             #+#    #+#             */
/*   Updated: 2024/11/28 08:21:21 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_name(char *name)
// check the file name must be .ber
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
			write(2, "Error\nmap must be name .ber\n", 28);
			exit(1);
		}
	}
}

void	check_empty(char *map)
// check if the file map is empty.
{
	int		fd;
	char	buff[1];
	int		byte_read;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nno such file or no permission to read\n", 44);
		exit(1);
	}
	byte_read = read(fd, buff, 1);
	close(fd);
	if (byte_read == 0)
	{
		write(2, "Error\nempty map\n", 16);
		exit(1);
	}
}

void	check_size(t_vars *vars)
// check if the map contains a wright size.
{
	int	size;
	int	i;
	int	j;

	size = 0;
	while (vars->map[0][size] != '\0')
		size++;
	i = 1;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0')
			j++;
		if (j != size)
			error_handle(vars);
		i++;
	}
}

void	check_sympol(t_vars *vars)
// check if the map it contains the required characters.
{
	int	i;
	int	j;
	int	count_exit;
	int	count_player;

	i = -1;
	count_exit = 0;
	count_player = 0;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (check_char(vars->map[i][j]) == 1)
				error_handle(vars);
			if (vars->map[i][j] == 'E')
				count_exit++;
			if (vars->map[i][j] == 'P')
				count_player++;
		}
	}
	if (count_exit != 1 || count_player != 1)
		error_handle(vars);
}

void	check_wall(t_vars *vars)
// check if the map urrounded by walls.
{
	int	i;
	int	height;

	height = 0;
	i = 0;
	while (vars->map[height])
	{
		height++;
	}
	while (vars->map[0][i])
	{
		if (vars->map[0][i] != '1' || vars->map[height - 1][i] != '1')
			error_handle(vars);
		i++;
	}
	i = 0;
	while (vars->map[i] != NULL)
	{
		if (vars->map[i][0] != '1' || vars->map[i][ft_strlen(vars->map[0])
			- 1] != '1')
			error_handle(vars);
		i++;
	}
}
