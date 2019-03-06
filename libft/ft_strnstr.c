/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 21:46:39 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/12 21:46:39 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (haystack[i] && (i < len))
	{
		while ((haystack[i + j] == needle[j]) && needle[j] && ((i + j) < len))
			j += 1;
		if (!needle[j])
			return ((char *)&haystack[i]);
		j = 0;
		i += 1;
	}
	if (!needle[0])
		return ((char *)&haystack[i]);
	return (NULL);
}
