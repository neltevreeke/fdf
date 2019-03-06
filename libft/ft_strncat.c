/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 15:44:53 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/10 15:44:56 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	c;

	c = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[c] != '\0' && c != n)
	{
		s1[i] = s2[c];
		c++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
