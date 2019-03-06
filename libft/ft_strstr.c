/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 20:15:48 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/12 20:15:48 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	n;
	int	h;
	int	a;

	h = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[h])
	{
		n = 0;
		a = h;
		while (needle[n] == haystack[a] && needle[n] && haystack[a])
		{
			n++;
			a++;
		}
		if (needle[n] == '\0')
			return ((char*)&haystack[h]);
		h++;
	}
	return (NULL);
}
