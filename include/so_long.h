/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:03:08 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/20 13:36:45 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef MAX_LINES
#  define MAX_LINES 100
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include "mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_var
{
	int		i_wid;
	int		i_hei;
	int		w_width;
	int		w_height;
	int		player_x;
	int		player_y;
	int		fd;
	int		count_collect;
	void	*mlx;
	void	*win;
	void	*img;
	void	*p;
	void	*wall;
	void	*c;
	void	*em;
	void	*ex;
	void	*en;
	char	**map;
	char	**copy_map_2;
	char	**copy_map;
}			t_vars;

size_t		ft_strlen(char *str);
char		*ft_strchr(char *str, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);
void		ft_free_string(char **str);
void		ft_free(t_vars *vars);
void		check(t_vars *vars);
int			check_char(char c);
void		check_sympol(t_vars *vars);
char		*ft_strcpy(char *dest, char *src);
void		calculate(t_vars *vars);
int			check_exit(char **str);
void		put_map(t_vars *vars, int i, int j);
void		render_map(t_vars *vars);
void		get_position(t_vars *vars);
int			clear_draw(t_vars *vars, int new_x, int new_y);
void		putnbr(int n);
int			key_hook(int keycode, t_vars *vars);
void		free_win(t_vars *vars);
void		error_handle(t_vars *vars);
int			close_window(t_vars *vars);
void		xpm_to_file(t_vars *vars);
void		check_wall(t_vars *vars);
int			check_map(t_vars *vars);
void		flood_fill(t_vars *vars, int x, int y);
void		read_map(t_vars *vars, char *file_map);
void		check_empty(char *map);

#endif
