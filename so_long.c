/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:43:13 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/12 19:21:39 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "mlx.h"
#include <X11/keysym.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_var
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*player_img;
	void	*wall_img;
	void	*collectible_img;
	void	*empty_space_img;
	void	*exit_img;
    void    *enemy_img;
	char	**map;
	int		img_width;
	int		img_height;
	int		window_width;
	int		window_height;
    int     player_x;
    int     player_y;
}			t_vars;

#define MAX_LINES 10000

void	ft_free(t_vars *vars)
{
    int i;

    i = 0;
    while (vars->map[i])
    {
        free(vars->map[i]);
        i++;
    }
    free(vars->map);
    if (vars->collectible_img && vars->win && vars->wall_img && vars->player_img && vars->empty_space_img && vars->exit_img)
    {
        mlx_destroy_image(vars->mlx, vars->collectible_img);
        mlx_destroy_image(vars->mlx, vars->empty_space_img);
        mlx_destroy_image(vars->mlx, vars->exit_img);
        mlx_destroy_image(vars->mlx, vars->player_img);
        mlx_destroy_image(vars->mlx, vars->wall_img);
        mlx_destroy_window(vars->mlx, vars->win);
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
    }
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
		{
			ft_free(vars);
			exit(1);
		}
		i++;
	}
}

void	check_sympol(t_vars *vars)
{
	int	i;
	int	j;
    int count_exit;
    int count_player;

	i = 0;
    count_exit = 0;
    count_player = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] != '1' && vars->map[i][j] != '0' && vars->map[i][j] != 'C'
				&& vars->map[i][j] != 'P' && vars->map[i][j] != 'E'
				&& vars->map[i][j] != '\n' && vars->map[i][j] != 'A')
			{
				ft_free(vars);
				exit(1);
			}
            if (vars->map[i][j] == 'E')
                count_exit++;
            if (vars->map[i][j] == 'P')
                count_player++;
			j++;
		}
		i++;
	}
    if (count_exit != 1 || count_player != 1)
    {
        ft_free(vars);
        exit(1);
    }
}

void	read_map(char *argv, t_vars *vars)
{
	int		fd;
	char	*str;
	int		count;
	size_t	len;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(1);
	count = 0;
	vars->map = malloc(MAX_LINES * sizeof(char *));
	while (count < MAX_LINES)
	{
        str = get_next_line(fd);
        if (str == NULL)
            break;
		len = strlen(str);
		vars->map[count] = (char *)malloc(len + 1);
		if (!vars->map[count])
		{
			free(str);
			break ;
		}
		strcpy(vars->map[count], str);
		free(str);
		count++;
	}
	vars->map[count] = NULL;
	close(fd);
}

void	calculate(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[0][i] != '\n')
		i++;
	j = 0;
	while (vars->map[j] != NULL)
		j++;
	vars->window_height = j * 60;
	vars->window_width = i * 60;
}

void	render_map(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map[++i] != NULL)
	{
		j = -1;
		while (vars->map[i][++j] != '\0' && vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall_img, j
						* vars->img_width, i * vars->img_height);
			else if (vars->map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player_img,
						j * vars->img_width, i * vars->img_height);
			else if (vars->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
						vars->collectible_img, j * vars->img_width, i
						* vars->img_height);
			else if (vars->map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win,
						vars->empty_space_img, j * vars->img_width, i
						* vars->img_height);
            else if (vars->map[i][j] == 'A')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy_img, j * vars->img_width, i * vars->img_height);
            else if (vars->map[i][j] == 'E')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_img, j * vars->img_width, i * vars->img_height);
		}
	}
}

void get_position(t_vars *vars)
{
    int i;
    int j;

    i = 0;
    while (vars->map[i])
    {
        j = 0;
        while (vars->map[i][j])
        {
            if (vars->map[i][j] == 'P')
            {
                vars->player_x = j;
                vars->player_y = i;
            }
            j++;
        }
        i++;
    }
}

int key_hook(int keycode, t_vars *vars)
{
    int new_x;
    int new_y;

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
    {
        ft_free(vars);
        exit(0);
    }
    if (vars->map[new_y][new_x] != '1')
    {
        if (vars->map[new_y][new_x] == 'C')
            vars->map[new_y][new_x] = '0';
        else if (vars->map[new_y][new_x] == 'E')
        {
            ft_free(vars);
            write(1, "Winner :)\n", 11);
            exit(0);
        }
        else if (vars->map[new_y][new_x] == 'A')
        {
            ft_free(vars);
            write(1, "Losser :(\n", 11);
            exit(0);
        }
        vars->map[vars->player_y][vars->player_x] = '0';
        vars->player_x = new_x;
        vars->player_y = new_y;
        vars->map[vars->player_y][vars->player_x] = 'P';
        mlx_clear_window(vars->mlx, vars->win);
        write(1, "move\n", 5);
        render_map(vars);
    }
    return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2 || argv[1][0] == '\0')
		return (perror("Inalid input"), 1);
	read_map(argv[1], &vars);
	check(&vars);
	check_sympol(&vars);
	calculate(&vars);
    get_position(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.window_width, vars.window_height,
			"so_long");
	vars.player_img = mlx_xpm_file_to_image(vars.mlx, "player.xpm",
			&vars.img_width, &vars.img_height);
	vars.wall_img = mlx_xpm_file_to_image(vars.mlx, "wall.xpm", &vars.img_width,
			&vars.img_height);
	vars.collectible_img = mlx_xpm_file_to_image(vars.mlx, "collectible.xpm",
			&vars.img_width, &vars.img_height);
	vars.empty_space_img = mlx_xpm_file_to_image(vars.mlx, "empty.xpm",
			&vars.img_height, &vars.img_height);
    vars.exit_img = mlx_xpm_file_to_image(vars.mlx, "exit.xpm", &vars.img_height, &vars.img_width);
    vars.enemy_img = mlx_xpm_file_to_image(vars.mlx, "enemy.xpm", &vars.img_height, &vars.img_width);
	if (!vars.player_img || !vars.wall_img || !vars.collectible_img
		|| !vars.empty_space_img)
		return (ft_free(&vars), perror("Failed to load images"), 1);
	render_map(&vars);
    mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
