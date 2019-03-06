/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 20:52:47 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/13 20:52:47 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *b;

	b = (unsigned char*)s;
	while (n > 0)
	{
		if (*b == (unsigned char)c)
			return (b);
		b++;
		n--;
	}
	return (NULL);
}
