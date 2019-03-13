/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/27 15:35:39 by wvan-dam       #+#    #+#                */
/*   Updated: 2019/03/11 12:41:52 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
#define PI 3.14159265358979323846

#include "./minilibx_macos/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include <math.h>

typedef struct		s_cam
{
	double			alpha;
	double			beta;
	double			gamma;
	double			zoom;
	int				iso;
}					t_cam;

typedef struct		s_dim
{
	int 			x;
	int 			y;
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
	struct s_cam 	*cam;
}					t_mlx;

void				ft_error(int argc, char **argv);
void				ft_error_2(void);
void				ft_window(t_mlx *mlx);
int					deal_mouse(int button, int x, int y, t_mlx *mlx);
int					deal_key(int key, t_mlx *mlx);
void				ft_malloc_tab(char *str, t_mlx *mlx);
void				ft_fill_tab(t_mlx *mlx, char *src);
t_dim				ft_rot_matrix(t_dim p, t_mlx *mlx);
t_dim				rotate_x(t_dim p, t_mlx *mlx);
t_dim				rotate_y(t_dim p, t_mlx *mlx);
t_dim				rotate_z(t_dim p, t_mlx *mlx);
t_dim				set_dim(t_dim p, t_mlx *mlx, int x, int y);
void				draw_line(t_dim p1, t_dim p2, t_mlx *mlx);
int					ft_width_window(t_mlx *mlx);
int					ft_height_window(t_mlx *mlx);
int					draw_map(t_mlx *mlx);
void				no_file(void);

#endif
