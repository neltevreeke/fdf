/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:52:17 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/05 15:25:20 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
