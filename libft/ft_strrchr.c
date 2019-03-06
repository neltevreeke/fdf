/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 18:35:15 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/10 18:35:18 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	p;

	p = c;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[i] != p && i >= 0)
		i--;
	if (s[i] == p)
		return ((char*)&s[i]);
	return (NULL);
}
