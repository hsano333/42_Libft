/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:22:52 by hsano             #+#    #+#             */
/*   Updated: 2022/07/16 05:55:03 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	unsigned char	*dst_p;
	unsigned char	*src_p;

	if (len == 0)
		return (dst);
	else if (dst == NULL && src == NULL)
		return (NULL);
	if (src >= dst || src + len <= dst)
		ft_memcpy(dst, src, len);
	else
	{
		i = len;
		//i = 0;
		dst_p = (unsigned char *)&(dst[len - 1]);
		src_p = (unsigned char *)&(src[len - 1]);
		while (i--)
			*(dst_p--) = *(src_p--);
	}
	return (dst);
}
