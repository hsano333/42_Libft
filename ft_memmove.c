/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:22:52 by hsano             #+#    #+#             */
/*   Updated: 2022/07/09 00:55:57 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	int		flag;

	i = -1;
	if (src >= dst || src + len <= dst)
		while (i++ < n)
			dst[i] = src[i];
	else
		i = src
		while (i-- < n)
			dst[i] = src[i];
	return dst;
}
