/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 12:21:44 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/13 12:21:45 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *a;

	a = b;
	while (len > 0)
	{
		*a = c;
		a++;
		len--;
	}
	return (b);
}
