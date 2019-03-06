/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 11:58:14 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/17 11:58:15 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*linesaver(char const *s, int c, int start, int d)
{
	int		i;
	char	*str;

	i = 0;
	while (s[d] == ' ' || s[d] == '\n' || s[d] == '\t' || s[d] == '\0')
	{
		d--;
		c--;
	}
	if (!(str = (char*)malloc(sizeof(char) * c + 2)))
		return (NULL);
	while (i <= c)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		c;
	int		start;

	i = 0;
	c = 0;
	start = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		if (s[i + 1] == '\0')
			return (ft_strnew(0));
		i++;
		start++;
	}
	while (s[i] != '\0')
	{
		c++;
		i++;
	}
	if (i == 0)
		return (ft_strnew(0));
	return (linesaver(s, c, start, i));
}
