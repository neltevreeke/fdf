/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:51:14 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/11 12:29:21 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Mallocs 2d int array
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
** Checks if input is a negative number
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
** Fills the 2d array with the input
*/

void	ft_fill_tab(t_mlx *mlx, char *src)
{
	char *line;
	int fd;
	int i;
	int j;
	int count;
	int first_count;

	j = 0;
	fd = open(src, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		i = 0;
		count = 0;
		while (*line)
		{
			if (*line == '\0' || count == mlx->size_x)
			 	break ;
			if (ft_isdigit(*line) == 1 || isnegnumber(line) == 1)
			{
				mlx->map[j][i] = ft_atoi(line);
				i++;
				count++;
			}
			while (*line != ' ' && *line != '\0' && *line != '\t')
				line++;
			if (*line == ' ' || *line == '\t' || *line == '\0')
				line++;
		}
		j++;
		if (first_count == 0)
			first_count = count;
		else if (first_count != count)
		{
			ft_putendl("Found wrong line length. Exiting.");
			exit(1);
		}
	}
	close(fd);
	return ;
}
