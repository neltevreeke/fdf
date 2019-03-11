/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvreeke <nvreeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 13:39:05 by wvan-dam       #+#    #+#                */
/*   Updated: 2019/03/11 12:12:41 by nvreeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>

# define BUFF_SIZE 1
# define MALLOCCHECK(x) if (!x) return (-1);

int						get_next_line(const int fd, char **line);
#endif
