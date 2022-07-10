/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:22:52 by hsano             #+#    #+#             */
/*   Updated: 2022/07/10 16:51:55 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (src >= dst || src + len <= dst)
		while (i++ < len)
			((char *)dst)[i] = ((char *)src)[i];
	else
		i = ft_strlen(src);
		while (i--)
			((char *)dst)[i] = ((char *)src)[i];
	return dst;
}
