/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:19:10 by salam             #+#    #+#             */
/*   Updated: 2024/11/16 12:31:18 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	malloc_maps(t_vars *vars)
{
	vars->map = (char **)malloc(MAX_LINES * sizeof(char *) + 1);
	vars->copy_map = (char **)malloc(MAX_LINES * sizeof(char *) + 1);
	vars->copy_map_2 = (char **)malloc(MAX_LINES * sizeof(char *) + 1);
	if (vars->map == NULL || vars->copy_map == NULL || vars->copy_map_2 == NULL)
		exit(1);
}

void	read_map(t_vars *vars)
{
	char	*str;
	int		count;

	count = -1;
	malloc_maps(vars);
	while (++count < MAX_LINES)
	{
		str = get_next_line(vars->fd);
		if (str == NULL)
			break ;
		vars->map[count] = ft_strcpy(vars->map[count], str);
		vars->copy_map[count] = ft_strcpy(vars->copy_map[count], str);
		vars->copy_map_2[count] = ft_strcpy(vars->copy_map_2[count], str);
		if (!vars->map[count] || !vars->copy_map[count] || !vars->copy_map_2)
		{
			free(str);
			break ;
		}
		free(str);
	}
	vars->map[count] = NULL;
	vars->copy_map[count] = NULL;
	vars->copy_map_2[count] = NULL;
	close(vars->fd);
}

void	init(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->img = NULL;
	vars->p = NULL;
	vars->wall = NULL;
	vars->c = NULL;
	vars->em = NULL;
	vars->ex = NULL;
	vars->en = NULL;
	vars->map = NULL;
	vars->copy_map = NULL;
	vars->copy_map_2 = NULL;
	vars->i_wid = 0;
	vars->i_hei = 0;
	vars->w_width = 0;
	vars->w_height = 0;
	vars->player_x = 0;
	vars->player_y = 0;
	vars->fd = 0;
	vars->count_collect = 0;
}
