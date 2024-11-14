/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:03:08 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/14 17:55:39 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef MAX_LINES
#  define MAX_LINES 1000
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_var
{
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
	char	**copy_map;
	int		i_wid;
	int		i_hei;
	int		w_width;
	int		w_height;
	int		player_x;
	int		player_y;
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
int			close_window(t_vars *vars);
void		xpm_to_file(t_vars *vars);
void		check_wall(t_vars *vars);
void		read_map(char *argv, t_vars *vars);

#endif
