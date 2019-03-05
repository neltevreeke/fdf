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
	void			*win;
	void			*mlx;
	struct s_cam	*cam;
}					t_mlx;

typedef struct		
{

};


void		ft_error(int argc, char **argv);
void		ft_window(int **tab);
void		ft_draw_line(int **tab, t_mlx *lst);
int			deal_mouse(int button, void *window);
int			deal_key(int key, void *window, t_mlx *mlx);
int			**ft_malloc_tab(char *str);
int			**ft_fill_tab(int **tab, char *src);
//void		ft_rot_matrix(t_dim *lst);
void		rotate_x(t_dim *lst);
void		rotate_y(t_dim *lst);
void		rotate_z(t_dim *lst);

#endif
