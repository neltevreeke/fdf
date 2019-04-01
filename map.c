/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 15:50:36 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/04/01 15:50:36 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Draws the full map.
*/

static void			draw_map_2(int x, int y, t_mlx *mlx)
{
	t_dim	p1;
	t_dim	p2;

	while (x < mlx->size_x)
	{
		p1 = set_dim(p1, mlx, x, y);
		p1 = ft_rot_matrix(p1, mlx);
		if (x + 1 < mlx->size_x)
		{
			p2 = set_dim(p2, mlx, x + 1, y);
			p2 = ft_rot_matrix(p2, mlx);
			draw_line(p1, p2, mlx);
		}
		if (y + 1 < mlx->size_y)
		{
			p2 = set_dim(p2, mlx, x, y + 1);
			p2 = ft_rot_matrix(p2, mlx);
			draw_line(p1, p2, mlx);
		}
		x++;
	}
}

int					draw_map(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	ft_bzero(mlx->data_addr, (ft_height_window(mlx) *
	ft_width_window(mlx)) * (mlx->bits_in_pixel / 8));
	while (y < mlx->size_y)
	{
		x = 0;
		draw_map_2(x, y, mlx);
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
