/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:40:22 by hsano             #+#    #+#             */
/*   Updated: 2022/07/15 01:14:04 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	t_list *tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->next = lst;
	f(tmp->next);
	del(tmp->next);


	return tmp;
}
