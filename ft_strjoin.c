/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:57:17 by hsano             #+#    #+#             */
/*   Updated: 2022/07/15 00:20:26 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*init(char *s1, char *s2, size_t *s1_len, size_t *s2_len)
{
	char	*p;
	size_t	sum;

	*s1_len = ft_strlen(s1);
	*s2_len = ft_strlen(s2);
	sum = *s1_len + *s2_len;
	p = malloc(sum + 1);
	if (!p)
		return (NULL);
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	k;
	char	*p;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	k = 0;
	p = init((char *)s1, (char *)s2, &s1_len, &s2_len);
	if (!p)
		return (NULL);
	while (i < s1_len)
	{
		p[i] = s1[i];
		i++;
	}
	while (k < s2_len)
	{
		p[i + k] = s2[k];
		k++;
	}
	p[s1_len + s2_len] = '\0';
	return (p);
}
