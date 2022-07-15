/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:38:37 by hsano             #+#    #+#             */
/*   Updated: 2022/07/15 16:24:44 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;
	t_list *next;
	if (!del || !lst)
		return ;
	if (!(*del))
	{
		*lst = NULL;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
	{
		next = tmp->next;
		ft_lstdelone(tmp, del);
		free(tmp);
		tmp = next;
	}
	ft_lstdelone(tmp, del);
	free(tmp);
	*lst = NULL;
}
