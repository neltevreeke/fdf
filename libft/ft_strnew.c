/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 11:07:52 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/16 11:07:54 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char*)malloc(sizeof(char) * size + 1);
	if (!s)
		return (NULL);
	while (i < size + 1)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
