/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:48:41 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/18 14:46:57 by nvreeke       ########   odam.nl         */
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
		exit(0);
	}
}

void	ft_wrong_line_len(void)
{
	ft_putendl("Found wrong line length. Exiting.");
	exit(0);
}

void	no_file(void)
{
	ft_putendl("File doesn't exist or you don't have the right permissions.");
	exit(0);
}
