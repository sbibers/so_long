/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_100_salam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:01:15 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/11 16:48:04 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <X11/keysym.h>
#include <stdio.h>
#include  <unistd.h>
#include <stdlib.h>

#define WIDTH 900
#define HEIGHT 720

typedef struct s_vars
{
    void *mlx;
    void *win;
    void *img;
    int img_width;
    int img_height;
}   t_vars;

void ft_free(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
}

int render(t_vars *vars)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
            x += vars->img_width;
        }
        y += vars->img_height;
    }
    return (0);
}

int main()
{
    t_vars vars;
    int width_image;
    int height_image;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "salam");
    vars.img = mlx_xpm_file_to_image(vars.mlx, "collectible.xpm", &width_image, &height_image);
    if (vars.img == NULL)
        return (ft_free(&vars), 1);
    vars.img_width = width_image;
    vars.img_height = height_image;
    mlx_loop_hook(vars.mlx, render, &vars);
    render(&vars);
    mlx_loop(vars.mlx);
    return (0);
}
