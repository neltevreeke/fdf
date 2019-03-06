/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 17:00:43 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/20 17:00:43 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmpnext;

	if (!alst || !del)
		return ;
	tmp = *alst;
	while (tmp)
	{
		tmpnext = tmp->next;
		del((tmp->content), (tmp->content_size));
		free(tmp);
		tmp = tmpnext;
	}
	*alst = NULL;
}
