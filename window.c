/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:49:35 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/05 16:06:40 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(1);
	else if (key == 125)
		mlx->cam->alpha += 0.05;
	else if (key == 126)
		mlx->cam->alpha -= 0.05;
	else if (key == 124)
		mlx->cam->beta += 0.05;
	else if (key == 123)
		mlx->cam->beta -= 0.05;
	return (0);
}

int		deal_mouse(int button, void *window)
{
	if (button == 1)
		ft_putendl("Mousebutton 1 clicked");
	return (0);
}

t_dim	set_dim(t_dim p, int **map, int x, int y)
{
	// if (x == 0)
	// 	p.x = 215;
	// else
		p.x = x * 30;
	// if (y == 0)
	// 	p.y = 215;
	// else
		p.y = y * 30;
	p.z = map[y][x] * 10;
	return (p);
}

int		draw_map(t_mlx *mlx)
{
	t_dim	p1;
	t_dim	p2;
	int		x;
	int		y;

	y = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	while (y < mlx->size_y)
	{
		x = 0;
		while (x < mlx->size_x)
		{
			p1 = set_dim(p1, mlx->map, x, y);
			p2 = set_dim(p2, mlx->map, x + 1, y);
			p1 = ft_rot_matrix(p1, mlx);
			p2 = ft_rot_matrix(p2, mlx);
			if (x + 1 < mlx->size_x)
				draw_line(p1, p2, mlx);		
			p2 = set_dim(p2, mlx->map, x, y + 1);
			p2 = ft_rot_matrix(p2, mlx);
			if (y + 1 < mlx->size_y)
				draw_line(p1, p2, mlx);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_window(t_mlx *mlx)
{
	void *window;

	window = mlx_new_window(mlx->mlx, 1000, 1000, "Neltes & Wouters fdf project");
	mlx->win = window;
	draw_map(mlx);
	mlx_hook(mlx->win, 2, 1L<<2, deal_key, mlx);
	mlx_mouse_hook(mlx->win, deal_mouse, mlx);
	mlx_loop_hook(mlx->mlx, &draw_map, mlx);
	mlx_loop(mlx->mlx);
}
