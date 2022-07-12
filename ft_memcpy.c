/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:19:46 by hsano             #+#    #+#             */
/*   Updated: 2022/07/13 04:01:39 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (n == 0)
		return (dst);
	else if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int main(int argc,char **argv)
//{
//	char *s1;
//	char *s2;
//	char *s3;
//	char *s4;
//	char *o1;
//	char *o2;
//	size_t		len;
//	if (argc == 6)
//	{
//		s1 = argv[1];
//		s2 = argv[2];
//		s3 = argv[3];
//		s4 = argv[4];
//		if (s1[0] == '\0')
//			s1 = NULL;
//		if (s2[0] == '\0')
//			s2 = NULL;
//		if (s3[0] == '\0')
//			s3 = NULL;
//		if (s4[0] == '\0')
//			s4 = NULL;
//		len = atoi(argv[5]);
//		o1 = ft_memcpy(s1,NULL,len);
//		o2 = memcpy(NULL,NULL,len);
//		printf("s1=%s,s2=%s,len=%zu\n",s1,s2,len);
//		printf("s3=%s,s4=%s,len=%zu\n",s3,s4,len);
//		printf("my=%s,test=%s\n",o1,o2);
//
//	}
//	return (0);
//}
