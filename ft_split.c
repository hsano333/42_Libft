/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:58:17 by hsano             #+#    #+#             */
/*   Updated: 2022/07/12 01:00:17 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_split(char const *s, char c)
{
	char	**p;

	p = (char **)malloc(sizeof(char *) * sizeof(c));
	p[0] = (char *)malloc(sizeof(char) * sizeof(c));
	p[0][0] = ((char *)s)[0];
	return (p);
}
