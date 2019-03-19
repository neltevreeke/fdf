/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:51:14 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/19 14:51:52 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Mallocs 2d int array
*/

void		ft_malloc_tab2(int row, int col, t_mlx *mlx, int fd)
{
	mlx->map = (int**)malloc(sizeof(int*) * row);
	while (row > 0)
	{
		row--;
		mlx->map[row] = (int*)malloc(sizeof(int) * col);
	}
	close(fd);
}

void		ft_malloc_tab(char *str, t_mlx *mlx)
{
	char	*line;
	int		fd;
	int		col;
	int		row;

	col = 0;
	row = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		no_file();
	while (get_next_line(fd, &line))
	{
		if (!col)
			col = ft_wordcount(line, ' ');
		else if (col != ft_wordcount(line, ' '))
			ft_wrong_line_len();
		row++;
		free(line);
	}
	free(line);
	mlx->size_x = col;
	mlx->size_y = row;
	ft_malloc_tab2(row, col, mlx, fd);
}

/*
** Checks if input is a negative number
*/

int			isnegnumber(char *line)
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

void		while_fill(char *line, int j, int i, t_mlx *mlx)
{
	while (*line)
	{
		if (ft_isdigit(*line) == 1 || isnegnumber(line) == 1)
		{
			mlx->map[j][i] = ft_atoi(line);
			i++;
		}
		while (*line != ' ' && *line != '\0' && *line != '\t')
			line++;
		line = *line ? line + 1 : line;
	}
}

void		ft_fill_tab(t_mlx *mlx, char *src)
{
	char	*line;
	char	*tmp;
	int		fd;
	int		i;
	int		j;

	j = 0;
	fd = open(src, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		tmp = line;
		i = 0;
		while_fill(line, j, i, mlx);
		j++;
		free(tmp);
	}
	free(line);
	close(fd);
}
