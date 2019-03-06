/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 20:13:05 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/16 20:13:06 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		c;

	if (!s1 || !s2)
		return (NULL);
	c = 0;
	str = (char*)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2)) + 1);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[c];
		i++;
		c++;
	}
	c = 0;
	while (s2[c] != '\0')
	{
		str[i] = s2[c];
		i++;
		c++;
	}
	str[i] = '\0';
	return (str);
}
