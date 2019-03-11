/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:49:35 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/11 13:07:46 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_width_window(t_mlx *mlx)
{
	int width;
	width = mlx->size_x * 30 + 150;
	if (width > 1000)
		width = 1000;
	return (width);
}

int ft_height_window(t_mlx *mlx)
{
	int height;
	height = mlx->size_y * 30 + 150;
	if (height > 1000)
		height = 1000;
	return (height);
}

void ft_window(t_mlx *mlx)
{
	void *window;

	window = mlx_new_window(mlx->mlx, ft_width_window(mlx), ft_height_window(mlx), "Neltes & Wouters fdf project");
	printf("window pointer aangemaakt\n");
	mlx->win = window;
	printf("window pointer gezet in struct\n");
	draw_map(mlx);
	printf("tijd om getekend te hebben\n");
	mlx_hook(mlx->win, 2, 1L << 2, deal_key, mlx);
	printf("oepsie foutje in mlxhook deal key\n");
	mlx_hook(mlx->win, 4, 1L << 1, deal_mouse, mlx);
	printf("foutje in mlmxhook deal mouse\n");
	mlx_loop_hook(mlx->mlx, &draw_map, mlx);
	printf("LOLOLOL pointer aangemaakt\n");
	mlx_loop(mlx->mlx);
}
