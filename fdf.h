/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/27 15:35:39 by wvan-dam       #+#    #+#                */
/*   Updated: 2019/03/05 18:06:49 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define PI 3.14159265358979323846

# include "./minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <math.h>

typedef struct		s_cam
{
	double			alpha;
	double			beta;
	double			gamma;
}					t_cam;

typedef struct		s_dim
{
	int 			x;
	int 			y;
	int 			z;
}					t_dim;

typedef struct		s_mlx
{
	int				**map;
	int				size_x;
	int				size_y;
	void			*win;
	void			*mlx;
	struct s_cam	*cam;
}					t_mlx;

void		ft_error(int argc, char **argv);
void		ft_window(t_mlx *mlx);
int			deal_mouse(int button, void *window);
int			deal_key(int key, t_mlx *mlx);
void		ft_malloc_tab(char *str, t_mlx *mlx);
void		ft_fill_tab(t_mlx *mlx, char *src);
t_dim		ft_rot_matrix(t_dim p, t_mlx *mlx);
t_dim		rotate_x(t_dim p, t_mlx *mlx);
t_dim		rotate_y(t_dim p, t_mlx *mlx);
t_dim		rotate_z(t_dim p, t_mlx *mlx);
void 		draw_line(t_dim p1, t_dim p2, t_mlx *mlx);

#endif
