/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:51:14 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/11 13:06:10 by nvreeke       ########   odam.nl         */
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

	col = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		no_file();
	while (get_next_line(fd, &line))
	{
		col++;
		row = ft_wordcount(line, ' ');
		free(line);
	}
	free(line);
	mlx->size_x = row;
	mlx->size_y = col;
	printf("row: %d\n", row);
	printf("col: %d\n", col);
	mlx->map = (int**)malloc(sizeof(int*) * col);
	while (col > 0)
	{
		col--;
		mlx->map[col] = (int*)malloc(sizeof(int) * row);
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
	char *tmp;
	int fd;
	int i;
	int j;
	size_t count;
	int first_count;

	j = 0;
	fd = open(src, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		tmp = line;
		printf("line: %p\n", line);
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
		free(tmp);
		// printf("count: %d\n", count);
		// printf("x: %d\n", mlx->size_x);
		// if (count == mlx->size_x - 1)
		// 	ft_error_2();
	}
	free(line);
	close(fd);
	return ;
}

