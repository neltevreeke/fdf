/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_listcount.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 21:36:20 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/21 21:36:21 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_listcount(t_list *lst)
{
	t_list *current;
	size_t i;

	i = 0;
	current = lst;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}
