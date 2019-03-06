/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 13:39:05 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/23 13:39:06 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>

# define BUFF_SIZE 2
# define MALLOCCHECK(x) if (!x) return (-1);

int						get_next_line(const int fd, char **line);
#endif
