/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:01:53 by hsano             #+#    #+#             */
/*   Updated: 2022/07/14 22:54:42 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = n / (sizeof(unsigned long long) / sizeof(char));
	if (i > 0)
	{
		while (i--)
			((unsigned long long *)s)[i] = 0;
	}
	i = sizeof(unsigned long long);
	if (n >= i)
	{
		while (--i)
			((char *)s)[n - i] = 0;
	}
	else
	{
		while (n--)
			((char *)s)[n] = 0;
	}
}
