/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:19:10 by salam             #+#    #+#             */
/*   Updated: 2024/11/16 14:26:39 by salam            ###   ########.fr       */
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
