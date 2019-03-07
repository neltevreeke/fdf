/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:51:14 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/07 17:28:08 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Malloc Integer array with appropriate size
*/

void	ft_malloc_tab(char *str, t_mlx *mlx)
{
	char *line;
	int fd;
	int col;
	int row;

	mlx->map = NULL;
	col = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		col++;
		row = ft_wordcount(line, ' ');
	}
	mlx->size_x = row;
	mlx->size_y = col;
	mlx->map = (int**)malloc(sizeof(int*) * col);
	while (col >= 0)
	{
		mlx->map[col] = (int*)malloc(sizeof(int) * row);
		col--;
	}
	close(fd);
	return ;
}

/*
**	Checks for a negative number
*/

int		isnegnumber(char *line)
{
	if (*line == '-')
	{
		line++;
		if (ft_isdigit(*line) == 1)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

/*
**	Fills the array with the integers received from get next line function
*/

// uit deze functie komt de malloc double free error. Mogelijke relatie met verkeerd inlezen map

void	ft_fill_tab(t_mlx *mlx, char *src)
{
	char *line;
	int fd;
	int i;
	int j;
	j = 0;
	fd = open(src, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		while (*line)
		{
			if (ft_isdigit(*line) == 1 || isnegnumber(line) == 1)
			{
				mlx->map[j][i] = ft_atoi(line);
				i++;
			}
			line++;
			while (*line != ' ' && *line != '\0' && *line != '\t')
				line++;
			if (*line == '\0')
			 	break ;
		}
		j++;
	}
	close(fd);
	return ;
}
