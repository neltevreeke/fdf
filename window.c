/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:49:35 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/07 17:19:57 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Dynamically calculates width of the window
*/

int ft_width_window(t_mlx *mlx)
{
	int width;
	width = mlx->size_x * 30 + 150;
	if (width > 1000)
		width = 1000;
	return (width);
}

/*
**	Dynamically calculates height of the window
*/

int ft_height_window(t_mlx *mlx)
{
	int height;
	height = mlx->size_y * 30 + 150;
	if (height > 1000)
		height = 1000;
	return (height);
}

/*
**	Opens the window
*/

void ft_window(t_mlx *mlx)
{
	void *window;

	window = mlx_new_window(mlx->mlx, ft_width_window(mlx), ft_height_window(mlx), "Neltes & Wouters fdf project");
	mlx->win = window;
	printf("TEST 3\n");
	draw_map(mlx);																		// Hier komt de segfault vandaan. Mogelijk in relatie met af en toe verkeerd inlezen van map
	printf("TEST 4\n");
	mlx_hook(mlx->win, 2, 1L << 2, deal_key, mlx);
	mlx_hook(mlx->win, 4, 1L << 1, deal_mouse, mlx);
	mlx_loop_hook(mlx->mlx, &draw_map, mlx);
	mlx_loop(mlx->mlx);
}
