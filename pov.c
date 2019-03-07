/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pov.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:57:22 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/05 15:24:02 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_dim	ft_rot_matrix(t_dim p, t_mlx *mlx)
{
	//mlx->cam-> = (double)(PI / 4);
	p.x -= (mlx->size_x * 30) / 2;
	p.y -= (mlx->size_y * 30) / 2;
	p = rotate_x(p, mlx);
	p = rotate_y(p, mlx);
	p = rotate_z(p, mlx);
	p.x += ft_width_window(mlx) / 2;
	p.y += ft_height_window(mlx) / 2;
	//printf("x: %d\n y: %d\n", p.x, p.y);
	//iso(&p.x, &p.y, p.z);
	return (p);
}

t_dim	rotate_x(t_dim p, t_mlx *mlx)
{
	int tmp_y;

	tmp_y = p.y;
	p.y = tmp_y * cos(mlx->cam->alpha) - p.z * sin(mlx->cam->alpha);
	p.z = tmp_y * sin(mlx->cam->alpha) + p.z * cos(mlx->cam->alpha);
	return (p);
}

t_dim	rotate_y(t_dim p, t_mlx *mlx)
{
	int tmp_x;

	tmp_x = p.x;
	p.x = tmp_x * cos(mlx->cam->beta) + p.z * sin(mlx->cam->beta);
	p.z = -tmp_x * sin(mlx->cam->beta) + p.z * cos(mlx->cam->beta);
	return (p);
}

t_dim	rotate_z(t_dim p, t_mlx *mlx)
{
	int tmp_x;
	int tmp_y;

	tmp_x = p.x;
	tmp_y = p.y;
	p.x = tmp_x * cos(mlx->cam->gamma) - tmp_y * sin(mlx->cam->gamma);
	p.y = tmp_x * sin(mlx->cam->gamma) + tmp_y * cos(mlx->cam->gamma);
	return (p);
}