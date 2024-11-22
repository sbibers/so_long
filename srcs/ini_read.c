/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:19:10 by salam             #+#    #+#             */
/*   Updated: 2024/11/22 12:55:39 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_malloc(t_vars *vars, char *str)
{
	write(2, "Error\nfail allocate ft_strcpy\n", 30);
	free(str);
	if (vars->map != NULL)
		ft_free_string(vars->map);
	if (vars->copy_map != NULL)
		ft_free_string(vars->copy_map);
	if (vars->copy_map_2 != NULL)
		ft_free_string(vars->copy_map_2);
	close(vars->fd);
	exit(1);
}

static void	malloc_maps(t_vars *vars, char *file_map)
{
	vars->fd = open(file_map, O_RDONLY);
	if (vars->fd == -1)
	{
		write(2, "Error\nthis argument not a map\n", 30);
		exit(1);
	}
	vars->map = (char **)malloc((MAX_LINES * sizeof(char *)) + 1);
	vars->copy_map = (char **)malloc((MAX_LINES * sizeof(char *)) + 1);
	vars->copy_map_2 = (char **)malloc((MAX_LINES * sizeof(char *)) + 1);
	if (vars->map == NULL || vars->copy_map_2 == NULL || vars->copy_map == NULL)
	{
		write(2, "Error\nfaild allocate maps\n", 26);
		if (vars->map != NULL)
			ft_free_string(vars->map);
		if (vars->copy_map != NULL)
			ft_free_string(vars->copy_map);
		if (vars->copy_map_2 != NULL)
			ft_free_string(vars->copy_map_2);
		close(vars->fd);
		exit(1);
	}
}

static void	null_maps(t_vars *vars, int count)
{
	vars->map[count] = NULL;
	vars->copy_map[count] = NULL;
	vars->copy_map_2[count] = NULL;
	check(vars);
	calculate(vars);
}

void	read_map(t_vars *vars, char *file_map)
{
	char	*str;
	int		count;

	count = -1;
	malloc_maps(vars, file_map);
	while (++count <= MAX_LINES)
	{
		str = get_next_line(vars->fd);
		if (str == NULL)
			break ;
		else if (str[0] != '\n')
		{
			vars->map[count] = ft_strcpy(vars->map[count], str);
			vars->copy_map[count] = ft_strcpy(vars->copy_map[count], str);
			vars->copy_map_2[count] = ft_strcpy(vars->copy_map_2[count], str);
			if (!vars->map[count] || !vars->copy_map[count]
				|| !vars->copy_map_2[count])
				check_malloc(vars, str);
		}
		else
			count--;
		free(str);
	}
	close(vars->fd);
	null_maps(vars, count);
}
