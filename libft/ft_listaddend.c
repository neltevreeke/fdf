/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_listaddend.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 21:36:33 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/21 21:36:34 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_listaddend(t_list **alst, t_list *new)
{
	t_list *elem;

	if (new == NULL)
		return ;
	if (*alst == NULL)
	{
		alst = &new;
		return ;
	}
	elem = *alst;
	while (elem->next != NULL)
		elem = elem->next;
	elem->next = new;
}
