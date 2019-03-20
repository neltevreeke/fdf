/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/27 15:35:39 by wvan-dam       #+#    #+#                */
/*   Updated: 2019/03/18 17:18:04 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define PI 3.14159265358979323846

# include "./minilibx_macos/mlx.h"
# include <stdlib.h>
# include "./libft/libft.h"
# include <math.h>
# include <stdio.h>

typedef struct		s_cam
{
	double			alpha;
	double			beta;
	double			gamma;
	double			zoom;
	int				iso;
	int				press;
}					t_cam;

typedef struct		s_dim
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_dim;

typedef struct		s_mlx
{
	int				**map;
	int				size_x;
	int				size_y;
	void			*win;
	void			*mlx;
	struct s_cam	*cam;

	/*
	**				IMG STUFF BABYYYYYY
	*/
	void			*img;
	char			*data_addr;
	int				bits_in_pixel;
	int				size_line;
	int				endian;
}					t_mlx;

/*
**	error functions
*/

void				ft_error(int argc, char **argv);
void				ft_window(t_mlx *mlx);
void				ft_wrong_line_len(void);
void				no_file(void);

/*
**	event handler functions
*/

int					deal_mouse(int button, int x, int y, t_mlx *mlx);
int					deal_key(int key, t_mlx *mlx);
int					deal_move(int x, int y, t_mlx *mlx);
int					deal_mouse_release(int button, int x, int y, t_mlx *mlx);

/*
**	integer array functions
*/

void				ft_malloc_tab(char *str, t_mlx *mlx);
void				ft_fill_tab(t_mlx *mlx, char *src);

/*
**	Rotation (algorithm) functions
*/

t_dim				ft_rot_matrix(t_dim p, t_mlx *mlx);
t_dim				rotate_x(t_dim p, t_mlx *mlx);
t_dim				rotate_y(t_dim p, t_mlx *mlx);
t_dim				rotate_z(t_dim p, t_mlx *mlx);
t_dim				set_dim(t_dim p, t_mlx *mlx, int x, int y);

/*
**	Line drawing (algorithm) functions
*/

int					draw_map(t_mlx *mlx);

/*
**	Color functions
*/

double				percent(int start, int end, int current);
int					get_light(int start, int end, double percentage);
int					get_color(t_dim current, t_dim start,
t_dim end, t_dim delta);

/*
**	Dynamic window functions
*/

int					ft_width_window(t_mlx *mlx);
int					ft_height_window(t_mlx *mlx);

#endif
