/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:03:08 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/28 08:21:45 by salam            ###   ########.fr       */
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
	int		move_count;
	void	*mlx;
	void	*win;
	void	*img;
	void	*p;
	void	*p_2;
	void	*wall;
	void	*c;
	void	*em;
	void	*ex;
	void	*en;
	char	**map;
	char	**copy_map;
	char	**copy_map_2;
}			t_vars;

// get_next_line.c
char		*get_next_line(int fd);

// get_next_line_utils.c
size_t		ft_strlen(char *str);
char		*ft_strchr(char *str, int c);
char		*ft_strjoin(char *s1, char *s2);

// ft_read_map.c
void		read_map(t_vars *vars, char *file_map);

// check_1.c
void		check_size(t_vars *vars);
void		check_sympol(t_vars *vars);
void		check_wall(t_vars *vars);
void		check_empty(char *map);
void		check_name(char *name);

// check_2.c
int			check_path(t_vars *vars);
int			check_char(char c);

//ft_free.c
void		ft_free_string(char **str);
void		ft_free(t_vars *vars);
void		free_win(t_vars *vars);
int			close_window(t_vars *vars);
void		error_handle(t_vars *vars);

// ft_key.c
int			key_hook(int keycode, t_vars *vars);
int			number_of_collect(char **str);

// ft_putmap.c
void		render_map(t_vars *vars, int flag);

// ft_putnbr.c
void		putnbr(int n);

// ft_itoa.c
char		*ft_itoa(int n);

// ft_split.c
char		**ft_split(char *s, char c);

#endif
