/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:48:41 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/11 12:29:48 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Error handlers
*/

void	ft_error(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf filename.fdf");
		exit(1);
	}
}