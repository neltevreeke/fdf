/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:51:14 by nvreeke        #+#    #+#                */
/*   Updated: 2019/03/05 16:27:05 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_malloc_tab(char *str)
{
	char *line;
	int fd;
	int **tab;
	int col;
	int row;

	tab = NULL;
	col = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		col++;
		row = ft_wordcount(line, ' ');
	}
	tab = (int**)malloc(sizeof(int*) * col);
	while (col >= 0)
	{
		tab[col] = (int*)malloc(sizeof(int) * row);
		col--;
	}
	close(fd);
	return (tab);
}

int		**ft_fill_tab(int **tab, char *src)
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
			if (ft_isdigit(*line) == 1)
			{
				tab[j][i] = ft_atoi(line);
				i++;
			}
			while (*line != ' ' && *line != '\0' && *line != '\t')
				line++;
			line++;
			if (*line == '\0')
			 	break ;
		}
		j++;
	}
	close(fd);
	return (tab);
}
