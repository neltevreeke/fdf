/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 19:08:43 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/08 19:30:59 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		l;
	int		i;
	char	*dup;

	i = 0;
	l = 0;
	while (src[l] != '\0')
		l++;
	if (!(dup = (char*)malloc(sizeof(char) * l + 1)))
		return (NULL);
	while (i < l)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
