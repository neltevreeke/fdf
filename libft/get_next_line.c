/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 12:43:25 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/31 12:43:26 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>

static char		*ft_strjchar(char *str, char c)
{
	char	*new_str;
	size_t	i;
	size_t	str_len;

	if (!str || !c)
		return (NULL);
	str_len = ft_strlen(str);
	new_str = ft_strnew(str_len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	free(str);
	return (new_str);
}

static int		ft_copytil(char **line, char *content, char c)
{
	int i;
	int count;
	int pos;

	i = 0;
	count = 0;
	while (content[i])
	{
		if (content[i] == c)
			break ;
		i++;
	}
	pos = i;
	while (content[count] && count < i)
	{
		*line = ft_strjchar(*line, content[count]);
		if (!line)
			return (0);
		count++;
	}
	return (pos);
}

t_list			*get_current(t_list **list, const int fd)
{
	t_list *tmp;

	tmp = *list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(list, tmp);
	return (tmp);
}

static int		ft_read(const int fd, t_list *current)
{
	int		ret;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		tmp = current->content;
		current->content = ft_strjoin(tmp, buf);
		MALLOCCHECK((current->content));
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	t_list			*current;
	char			*tmp;

	if (fd < 0 || line == NULL || (read(fd, buf, 0) < 0))
		return (-1);
	current = get_current(&list, fd);
	ret = 0;
	*line = ft_strnew(0);
	MALLOCCHECK((*line));
	ret = ft_read(fd, current);
	if (ret < BUFF_SIZE && ft_strlen(current->content) == 0)
		return (0);
	ret = ft_copytil(line, current->content, '\n');
	if (ret < (int)ft_strlen(current->content))
	{
		tmp = current->content;
		current->content = ft_strdup(current->content + ret + 1);
		free(tmp);
	}
	else
		ft_strclr(current->content);
	return (1);
}
