/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:52:17 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/11 13:14:15 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


/*
** Draws a line on the screen
*/
double percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(t_dim current, t_dim start, t_dim end, t_dim delta)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

    if (current.color == end.color)
        return (current.color);
    if (delta.x > delta.y)
        percentage = percent(start.x, end.x, current.x);
    else
        percentage = percent(start.y, end.y, current.y);
    red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
    green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
    blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}

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
		mlx_pixel_put(mlx->mlx, mlx->win, cur.x, cur.y, get_color(cur, p1, p2, delta)); //2550000 is babyblauw 9999900
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

t_dim set_dim(t_dim p, t_mlx *mlx, int x, int y)
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

int draw_map(t_mlx *mlx)
{
	t_dim p1;
	t_dim p2;
	int x;
	int y;

	y = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	while (y < mlx->size_y)
	{
		x = 0;
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
		y++;
	}
	return (0);
}
