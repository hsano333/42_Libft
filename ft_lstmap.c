/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:40:22 by hsano             #+#    #+#             */
/*   Updated: 2022/07/17 02:52:49 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*bk;
	t_list	*tmp;

	if (!f || !lst)
		return (NULL);
	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	bk = tmp;
	tmp->content = f(lst->content);
	while (lst->next)
	{
		tmp->next = (t_list *)malloc(sizeof(t_list));
		if (!tmp->next)
		{
			if (del)
				ft_lstclear(&bk, del);
			return (NULL);
		}
		lst = lst->next;
		tmp->next->content = f(lst->content);
		tmp = tmp->next;
	}
	return (bk);
}
