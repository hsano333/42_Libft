/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:26:36 by hsano             #+#    #+#             */
/*   Updated: 2022/07/12 00:58:41 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == c)
			return ((void *)(&(s[i])));
		i++;
	}
	return (0);
}
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int main(int argc, char **argv)
//{
//	int	test[] = {1,2,3,4,5,6,7,8,9,0,11,12,13,14};
//	char *p;
//	char *q;
//	int	len;
//
//	len = 5;
//	if (argc == 2)
//		len = atoi(argv[1]);
//	p = ft_memchr(test,3,len);
//	q = memchr(test,3,len);
//	printf("my:%p\n",p);
//	printf("test:%p\n",q);
//
//	p = ft_memchr(test,20,len);
//	q = memchr(test,20,len);
//	printf("my:%p\n",q);
//	printf("test:%p\n",p);
//	return (0);
//}
