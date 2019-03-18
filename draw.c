/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:52:17 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/18 17:42:18 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Calculates delta for x and y axis
*/

static void			put_pixel_to_img(int x, int y, t_mlx *mlx, int color)
{
	int i;

	if (x > 0 && x < ft_width_window(mlx) && y > 0 && y < ft_height_window(mlx->mlx))
	{
		i = (x * mlx->bits_in_pixel / 8) + (y * mlx->size_line);
		mlx->data_addr[i] = color;
		mlx->data_addr[++i] = color >> 8;
		mlx->data_addr[++i] = color >> 16;
	}
}

static t_dim		set_delta(t_dim p1, t_dim p2, t_dim delta)
{
	delta.x = abs(p2.x - p1.x);
	delta.y = abs(p2.y - p1.y);
	return (delta);
}

static t_dim		set_s(t_dim p1, t_dim p2, t_dim s)
{
	if (p1.x < p2.x)
		s.x = 1;
	else
		s.x = -1;
	s.x = p1.x < p2.x ? 1 : -1;
	if (p1.y < p2.y)
		s.y = 1;
	else
		s.y = -1;
	s.y = p1.y < p2.y ? 1 : -1;
	return (s);
}

/*
** Draws a line on the screen
*/

static void			draw_line(t_dim p1, t_dim p2, t_mlx *mlx)
{
	t_dim	delta;
	t_dim	s;
	t_dim	cur;
	int		e[2];

	delta = set_delta(p1, p2, delta);
	s = set_s(p1, p2, s);
	e[0] = delta.x - delta.y;
	cur = p1;
	while (cur.x != p2.x || cur.y != p2.y)
	{
		put_pixel_to_img(cur.x, cur.y, mlx, get_color(cur, p1, p2, delta));
		//mlx_pixel_put(mlx->mlx, mlx->win, cur.x,
		//cur.y, get_color(cur, p1, p2, delta));
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
** Sets dimensions for x, y & z
*/

t_dim				set_dim(t_dim p, t_mlx *mlx, int x, int y)
{
	p.x = x * mlx->cam->zoom;
	p.y = y * mlx->cam->zoom;
	p.z = mlx->map[y][x] * (mlx->cam->zoom / 3);
	if (mlx->map[y][x] > 4 && mlx->map[y][x] < 10)
		p.color = 0x424242;
	else if (mlx->map[y][x] >= 10)
		p.color = 0xFFFFFF;
	else if (mlx->map[y][x] <= 0)
		p.color = 30251;
	else
		p.color = 606000;
	return (p);
}

/*
** Draws the full map onto screen
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
	ft_bzero(mlx->data_addr, (ft_height_window(mlx) * ft_width_window(mlx)) * (mlx->bits_in_pixel / 8));
	while (y < mlx->size_y)
	{
		x = 0;
		draw_map_2(x, y, mlx);
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
