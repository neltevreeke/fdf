/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/07 16:02:01 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/18 17:40:13 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Deals with key events
*/

void	set_a_b_g(t_mlx *mlx)
{
	mlx->cam->alpha = 0;
	mlx->cam->beta = 0;
	mlx->cam->gamma = 0;
}

int		deal_key(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(0);
	else if (key == 125)
		mlx->cam->alpha += 0.05;
	else if (key == 126)
		mlx->cam->alpha -= 0.05;
	else if (key == 124)
		mlx->cam->beta += 0.05;
	else if (key == 123)
		mlx->cam->beta -= 0.05;
	else if (key == 49 && mlx->cam->iso == 0)
	{
		mlx->cam->iso = 1;
		set_a_b_g(mlx);
		mlx->cam->zoom = 30;
	}
	else if (key == 49 && mlx->cam->iso == 1)
	{
		mlx->cam->iso = 0;
		set_a_b_g(mlx);
		mlx->cam->zoom = 30;
	}
	return (0);
}

/*
** Deals with mouse events
*/

int		deal_mouse(int button, int x, int y, t_mlx *mlx)
{
	if (button == 5)
		mlx->cam->zoom += 0.02 * mlx->cam->zoom;
	if (button == 4)
		mlx->cam->zoom -= 0.02 * mlx->cam->zoom;
	return (0);
}
