/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:58:48 by maseidua          #+#    #+#             */
/*   Updated: 2018/11/11 18:06:57 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*head;

	if (!lst)
		return (NULL);
	tmp = (*f)(lst);
	head = tmp;
	while ((lst = lst->next))
	{
		tmp->next = (*f)(lst);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (head);
}
