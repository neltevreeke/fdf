/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 13:51:51 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/13 13:51:52 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *a;

	a = s;
	if (n == 0)
		return ;
	while (n > 0)
	{
		*a = '\0';
		a++;
		n--;
	}
	return ;
}
