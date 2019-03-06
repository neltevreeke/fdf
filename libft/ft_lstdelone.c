/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 16:17:14 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/20 16:17:15 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (!alst || !del)
		return ;
	temp = *alst;
	del(temp->content, temp->content_size);
	free(*alst);
	*alst = NULL;
	return ;
}
