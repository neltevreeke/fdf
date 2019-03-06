/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 17:18:44 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/10 17:18:49 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	p;

	p = c;
	i = 0;
	while (s[i] != p && s[i])
	{
		i++;
	}
	if (s[i] == p)
		return ((char*)&s[i]);
	return (NULL);
}
