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

int		deal_key(int key, void *window, t_mlx *mlx)
{
	if (key == 53)
		exit(1);
	// if (key == 49)
	// 	ft_rot_matrix(mlx);
	return (0);
}

int		deal_mouse(int button, void *window)
{
	if (button == 1)
		ft_putendl("Mousebutton 1 clicked");
	return (0);
}

void	draw_map(int **map, t_mlx *mlx)
{
	int x;
	int y;
	int size_x;
	int size_y;

	x = 0;
	y = 0;
	size_x = sizeof(map[y]);
	size_y = sizeof(map);
	printf("%d\n", map[2][2]);
}

void	ft_window(int **tab)
{
	void *mlx_ptr;
	void *window;
	t_mlx *mlx;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, 1000, 1000, "Neltes & Wouters fdf project");
	mlx->mlx = mlx_ptr;
	mlx->win = window;
	// ft_draw_line(tab, mlx);
	draw_map(tab, mlx);
	mlx_key_hook(mlx->win, deal_key, (void *)0);
	mlx_mouse_hook(mlx->win, deal_mouse, mlx);
	//mlx_loop_hook(mlx->mlx, &draw, );
	mlx_loop(mlx->mlx);
}
