/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:52:17 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/07 17:47:51 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Algorithm to draw a line in the window
*/

void 	draw_line(t_dim p1, t_dim p2, t_mlx *mlx)
{
	t_dim	delta;
	t_dim	s;
	t_dim	cur;
	int		e[2];

	delta.x = abs(p2.x - p1.x);
	delta.y = abs(p2.y - p1.y);
	s.x = p1.x < p2.x ? 1 : -1;
	s.y = p1.y < p2.y ? 1 : -1;
	e[0] = delta.x - delta.y;
	cur = p1;
	while (cur.x != p2.x || cur.y != p2.y)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, cur.x, cur.y, 9999900);
		e[1] = e[0] * 2;
		if (e[1] > -delta.y)
		{
			e[0] -= delta.y;
			cur.x += s.x;
		}
		if (e[1] < delta.x)
		{
			e[0] += delta.x;
			cur.y += s.y;
		}
	}
}

/*
**	Calculates the dimensions needed for our zoom
*/

t_dim set_dim(t_dim p, t_mlx *mlx, int x, int y)
{
	p.x = x * mlx->cam->zoom;
	p.y = y * mlx->cam->zoom;
	p.z = mlx->map[y][x] * (mlx->cam->zoom / 3);
	return (p);
}

/*
**	Draws the map into the window
*/

int draw_map(t_mlx *mlx)
{
	t_dim p1;
	t_dim p2;
	int x;
	int y;

	y = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	printf("Cleared window\n");
	while (y < mlx->size_y)
	{
		x = 0;
		while (x < mlx->size_x)
		{
			p1 = set_dim(p1, mlx, x, y);
			if (x + 1 < mlx->size_x)
				p2 = set_dim(p2, mlx, x + 1, y);
			p1 = ft_rot_matrix(p1, mlx);
			p2 = ft_rot_matrix(p2, mlx);
			if (x + 1 < mlx->size_x)
				draw_line(p1, p2, mlx);
			if (y + 1 < mlx->size_y)
			{
				p2 = set_dim(p2, mlx, x, y + 1);
				p2 = ft_rot_matrix(p2, mlx);
				draw_line(p1, p2, mlx);
			}
			x++;
		}
		y++;
	}
	return (0);
}