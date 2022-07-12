/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:44:14 by hsano             #+#    #+#             */
/*   Updated: 2022/07/12 03:07:29 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	size;

	size = 0;
	if (s != NULL)
		size = ft_strlen(s);
	if (size < start + len)
	{
		if (start >= size)
			len = 0;
		else
			len = size - start;
	}
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	p[len] = '\0';
	while (len--)
		p[len] = s[start + len];
	return (p);
}
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int main(int argc,char **argv)
//{
//	char *s1;
//	unsigned int start;
//	char	*result;
//	size_t		len;
//	if (argc == 4)
//	{
//		s1 = argv[1];
//		start = atoi(argv[2]);
//		len = atoi(argv[3]);
//		result = ft_substr(s1,start,len);
//		printf("result=%s\n",result);
//
//	}
//	return (0);
//}
