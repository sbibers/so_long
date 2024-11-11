/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dont_touch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 08:22:14 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/11 14:11:59 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/keysym.h>

typedef struct s_vars
{
    void *mlx;
    void *win;
    void *img;
    void *background_img;
    char *background_data;
    int   bits;
    int   size_line;
    int   endian;
    int   color;
    int   x;
    int   y;
}         t_vars;

#define WIDTH 1920
#define HEIGHT 1020

void ft_free(t_vars *vars)
{
        if (vars->background_data != NULL)
        {
            mlx_destroy_image(vars->mlx, vars->background_img);
        }
        mlx_destroy_window(vars->mlx, vars->win);
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
}

int handle_key(int keycode, t_vars *vars)
{
    if (keycode == XK_Escape)
    {
        mlx_destroy_image(vars->mlx, vars->img); // close image, and free image.
        mlx_destroy_image(vars->mlx, vars->background_img); // close background, and free background.
        mlx_destroy_window(vars->mlx, vars->win); // close window.
        mlx_destroy_display(vars->mlx); // close the connection with X11.
        free(vars->mlx);
        exit(0);
    }
    else if (keycode == XK_w) // 'W'
        vars->y -= 10;
    else if (keycode == XK_s) // 'S'
        vars->y += 10;
    else if (keycode == XK_a) // 'A'
        vars->x -= 10;
    else if (keycode == XK_d) // 'D'
        vars->x += 10;
    return (0);
}

void fill_background_red(t_vars *vars)
{
    int x;
    int y;
    int pixel;

    y = 0;
    while (y <= HEIGHT)
    {
        x = 0;
        while (x <= WIDTH)
        {
            pixel = (y * vars->size_line) + (x * (vars->bits / 8));
            vars->background_data[pixel] = 0;
            vars->background_data[pixel + 1] = 1;
            vars->background_data[pixel + 2] = 255;
            x++;
        }
        y++;
    }
}

int render(t_vars *vars)
{
    mlx_clear_window(vars->mlx, vars->win); // clear the window to make a background and put image from zero.
    mlx_put_image_to_window(vars->mlx, vars->win, vars->background_img, 0, 0); // put a background from index (0, 0) in a window.
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x, vars->y); // show the image that i would to move it.
    return (0);
}

int main()
{
    int width;
    int height;
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Moving Square"); // make a window.
    vars.background_img = mlx_new_image(vars.mlx, WIDTH, HEIGHT); // make a background.
    if (vars.background_img == NULL)
        return (ft_free(&vars), 1);
    vars.background_data = mlx_get_data_addr(vars.background_img, &vars.bits, &vars.size_line, &vars.endian); // take the size of image (image = background).
    fill_background_red(&vars); // draw the window (background).
    vars.x = WIDTH - 640; // the position of the image i will move it.
    vars.y = HEIGHT - 640; // the position of the image i will move it.
    vars.img = mlx_xpm_file_to_image(vars.mlx, "mario.xpm", &width, &height); // take the image from the file.xpm to put it in a window.
    if (vars.img == NULL)
        return (ft_free(&vars), 1);
    mlx_loop_hook(vars.mlx, render, &vars); // this function will make when every time function mlx_loop used.
    mlx_key_hook(vars.win, handle_key, &vars); // if i press the key.
    mlx_loop(vars.mlx); // this window will be executed for (n) time just when i press (esc) it will close. 
    return (0);
}
