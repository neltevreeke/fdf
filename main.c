/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 12:35:52 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/07 17:26:05 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int **tab;
	void *mlx_ptr;
	t_mlx *mlx;
	t_cam *cam;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx_ptr = mlx_init();
	mlx->mlx = mlx_ptr;
	cam = (t_cam*)malloc(sizeof(t_cam));
	mlx->cam = cam;
	mlx->cam->alpha = 0;
	mlx->cam->beta = 0;
	mlx->cam->gamma = 0;
	mlx->cam->zoom = 30;
	ft_error(argc, argv);;
	ft_malloc_tab(argv[1], mlx);
	ft_fill_tab(mlx, argv[1]);							// Malloc error sometimes (1 op 5 keer ongeveer);
	ft_window(mlx);										// segfault (redelijk vaak, major bug);
	return (0);
}
