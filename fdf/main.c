/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 12:35:52 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/04 13:07:49 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int **tab;

	ft_error(argc, argv);
	tab = ft_malloc_tab(argv[1]);
	tab = ft_fill_tab(tab, argv[1]);
	ft_window(tab);
	return (0);
}
