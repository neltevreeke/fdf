/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pov.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:57:22 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/05 15:24:02 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	ft_rot_matrix(t_mlx *lst)
// {
// 	lst->cam->alpha = 40;
// 	lst->cam->beta = 300;
// 	lst->cam->gamma = 70;

// 	lst->cam-> = (double)(PI / 4);
// 	rotate_x(lst);
// 	rotate_y(lst);
// 	rotate_z(lst);
// }

// void		rotate_x(t_dim *lst)
// {
// 	int tmp_y;

// 	tmp_y = lst->y;
// 	lst->y = tmp_y * cos(lst->angle) + lst->z * sin(lst->angle);
// 	lst->z = -tmp_y * sin(lst->angle) + lst->z * cos(lst->angle);
// }

// void		rotate_y(t_dim *lst)
// {
// 	int tmp_x;

// 	tmp_x = lst->x;
// 	lst->x = tmp_x * cos(lst->angle) + lst->z * sin(lst->angle);
// 	lst->z = -tmp_x * sin(lst->angle) + lst->z * cos(lst->angle);
// }

// void		rotate_z(t_dim *lst)
// {
// 	int tmp_x;
// 	int tmp_y;

// 	tmp_x = lst->x;
// 	tmp_y = lst->y;
// 	lst->x = tmp_x * cos(lst->angle) - tmp_y * sin(lst->angle);
// 	lst->y = tmp_x * sin(lst->angle) + tmp_y * cos(lst->angle);
// }
