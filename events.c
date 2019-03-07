/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/07 16:02:01 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/07 16:12:24 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int deal_key(int key, t_mlx *mlx)
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
	else if (key == 49 && mlx->cam->iso == 0)
	{
		mlx->cam->iso = 1;
		mlx->cam->alpha = 0;
		mlx->cam->beta = 0;
		mlx->cam->gamma = 0;
		mlx->cam->zoom = 30;
	}
	else if (key == 49 && mlx->cam->iso == 1)
	{
		mlx->cam->iso = 0;
		mlx->cam->alpha = 0;
		mlx->cam->beta = 0;
		mlx->cam->gamma = 0;
		mlx->cam->zoom = 30;
	}
	return (0);
}

int deal_mouse(int button, int x, int y, t_mlx *mlx)
{
	if (button == 5)
		mlx->cam->zoom += 1;
	if (button == 4)
		mlx->cam->zoom -= 1;
	return (0);
}
