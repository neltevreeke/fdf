/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:49:35 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/18 17:35:32 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_width_window(t_mlx *mlx)
{
	int		width;

	width = mlx->size_x * 30 + 150;
	if (width > 1000)
		width = 1000;
	return (width);
}

int			ft_height_window(t_mlx *mlx)
{
	int		height;

	height = mlx->size_y * 30 + 150;
	if (height > 1000)
		height = 1000;
	return (height);
}

void		ft_window(t_mlx *mlx)
{
	void	*window;

	window = mlx_new_window(mlx->mlx, ft_width_window(mlx),
	ft_height_window(mlx), "Neltes & Wouters fdf project");
	mlx->win = window;
	mlx->img = mlx_new_image(mlx->mlx,
	ft_width_window(mlx), ft_height_window(mlx));
	mlx->data_addr = mlx_get_data_addr(mlx->img, &(mlx->bits_in_pixel),
	&(mlx->size_line), &(mlx->endian));
	mlx_hook(mlx->win, 2, 1L << 2, deal_key, mlx);
	mlx_hook(mlx->win, 4, 1L << 1, deal_mouse, mlx);
	mlx_hook(mlx->win, 6, 1L << 8, deal_move, mlx);
	mlx_hook(mlx->win, 5, 1L << 3, deal_mouse_release, mlx);
	mlx_loop_hook(mlx->mlx, &draw_map, mlx);
	mlx_loop(mlx->mlx);
}
