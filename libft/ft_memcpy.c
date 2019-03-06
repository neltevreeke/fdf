/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 14:42:47 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/13 14:42:48 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*strd;
	size_t			i;

	strd = dst;
	i = 0;
	while (i < n)
	{
		*strd = ((unsigned char*)src)[i];
		i++;
		strd++;
	}
	return (dst);
}
