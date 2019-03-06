/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 13:27:32 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/01/21 13:27:33 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*temp;

	head = f(lst);
	temp = head;
	lst = lst->next;
	while (lst)
	{
		temp->next = f(lst);
		lst = lst->next;
		temp = temp->next;
	}
	return (head);
}
