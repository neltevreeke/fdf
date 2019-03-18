/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 12:35:52 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/18 17:33:23 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	int		**tab;
	void	*mlx_ptr;
	t_mlx	*mlx;
	t_cam	*cam;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx_ptr = mlx_init();
	mlx->mlx = mlx_ptr;
	cam = (t_cam*)malloc(sizeof(t_cam));
	mlx->cam = cam;
	mlx->cam->alpha = 0;
	mlx->cam->beta = 0;
	mlx->cam->gamma = 0;
	mlx->cam->zoom = 30;
	mlx->cam->iso = 0;
	ft_error(argc, argv);
	ft_malloc_tab(argv[1], mlx);
	ft_fill_tab(mlx, argv[1]);
	ft_window(mlx);
	return (0);
}
