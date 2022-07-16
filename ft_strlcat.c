/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 01:07:54 by hsano             #+#    #+#             */
/*   Updated: 2022/07/16 18:46:50 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_d;
	size_t	len_s;
	char	*p;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (len_d >= dstsize)
		return (len_s + dstsize);
	p = &(dst[len_d]);
	ft_strlcpy(p, src, dstsize - len_d);
	return (len_d + len_s);
}
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int main(int argc,char **argv)
//{
//	char s1[100] = {1};
//	char *s2;
//	char s3[100] = {1};
//	char *s4;
//	size_t o1;
//	size_t o2;
//	size_t		len;
//	if (argc == 6)
//	{
//		s2 = argv[2];
//		s4 = argv[4];
//		if (s1[0] == '\0')
//			(s1[0]) = 0;
//		else
//			ft_strlcpy(s1,argv[1], strlen(argv[1]));
//		if (s2[0] == '\0')
//			s2 = NULL;
//		if (s3[0] == '\0')
//			(s3[0]) = 0;
//		else
//			strlcpy(s3,argv[3], strlen(argv[3]));
//		printf("s3=%s, argv=%s,len=%zu\n",s3, argv[3],strlen(argv[3]));
//		if (s4[0] == '\0')
//			s4 = NULL;
//		len = atoi(argv[5]);
//		printf("my   s1=%s,s2=%s,len=%zu\n",s1,s2,len);
//		o1 = ft_strlcat(s1,s2,len);
//		printf("my   strlcat s1=%s,result=%zu\n",s1,o1);
//		printf("test   s3=%s,s4=%s,len=%zu\n",s3,s4,len);
//		o2 = 1;
//		o2 = strlcat(s3,s4,len);
//		printf("test strlcat s3=%s,result=%zu\n",s3,o2);
//		printf("my=%zu,test=%zu\n",o1,o2);
//
//	}
//	return (0);
//}
