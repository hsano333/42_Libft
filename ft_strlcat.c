/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 01:07:54 by hsano             #+#    #+#             */
/*   Updated: 2022/07/12 00:56:32 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char restrict *dst, const char restrict *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	d;

	d = ft_strlen(dst);
	if (d >= dstsize)
		return (ft_strlen(src) + dstsize);
	i = d;
	j = 0;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	while (src[j])
		j++;
	dst[i] = '\0';
	return (d + j);
}
