/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:55:56 by hsano             #+#    #+#             */
/*   Updated: 2022/07/11 19:34:39 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;

	s += i;
	i += 1;
	while (i--)
	{
		if (*s == (char)c)
			return (char *)(s);
		s--;
	}
	return (0);
}
//#include <stdio.h>
//#include <string.h>
//int main(void)
//{
//	//char test[] = "t1est12345";
//	char test[] = "abcdefg";
//	char *p;
//	char *q;
//
//	p = ft_strrchr(test,'a');
//	q = strrchr(test,'a');
//	printf("%s\n",p);
//	printf("%s\n",q);
//
//	p = ft_strrchr(test,'b');
//	q = strrchr(test,'i');
//	printf("%s\n",q);
//	printf("%s\n",p);
//	return (0);
//}
