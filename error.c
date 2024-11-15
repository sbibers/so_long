/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:27:19 by salam             #+#    #+#             */
/*   Updated: 2024/11/15 14:28:10 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_handle(t_vars *vars)
{
	write(2, "Error\nwrong map\n", 16);
	ft_free_string(vars->map);
	ft_free_string(vars->copy_map);
	exit(1);
}
