/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:45:30 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/16 11:12:29 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	len;

	len = ft_strlen(src);
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	len = 0;
	while (src[len])
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

void	check(t_vars *vars)
{
	int	size;
	int	i;
	int	j;

	size = 0;
	while (vars->map[0][size] != '\n' && vars->map[0][size] != '\0')
		size++;
	i = 1;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
			j++;
		if (j != size)
			error_handle(vars);
		i++;
	}
}

void	check_sympol(t_vars *vars)
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
{
	int	i;
	int	height;

	height = 0;
	i = 0;
	while (vars->map[height])
	{
		if (vars->map[height][0] == '\n')
			error_handle(vars);
		height++;
	}
	while (vars->map[0][i] && vars->map[0][i] != '\n')
	{
		if (vars->map[0][i] != '1' || vars->map[height - 1][i] != '1')
			error_handle(vars);
		i++;
	}
	i = 0;
	while (vars->map[i] != NULL)
	{
		if (vars->map[i][0] != '1' || vars->map[i][ft_strlen(vars->map[0])
			- 2] != '1')
			error_handle(vars);
		i++;
	}
}

int	check_char(char c)
{
	if (c != '1' && c != '0' && c != 'C' && c != 'P' && c != 'E' && c != '\n'
		&& c != 'A')
	{
		return (1);
	}
	return (0);
}
