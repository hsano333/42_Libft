/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:07:11 by hsano             #+#    #+#             */
/*   Updated: 2022/07/13 04:11:05 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	max;
	unsigned long long *p;
	char	*c;
	size_t	i;

	max = count * size;
	p = (unsigned long long *)malloc(max);
	c = (char *)p;
	i = max / (sizeof(unsigned long long) / sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i--)
		p[i] = 0;
	c = (char *)p;
	i = sizeof(unsigned long long);
	while (i--)
		c[max - i] = 0;
	return ((void *)c);
}
//#include <stdio.h>
//#include <time.h>
//int main(int argc, char** argv)
//{
//	char *s1;
//	char *s2;
//	size_t count;
//	size_t size;
//	clock_t start_clock1, end_clock1;
//	clock_t start_clock2, end_clock2;
//	size_t	max;
//
//	printf("%zu\n",sizeof(double)/sizeof(char));
//	if (argc == 3)
//	{
//		count = (size_t)atoi(argv[1]);
//		size = (size_t)atoi(argv[2]);
//		max = count*size;
//
//		start_clock1 = clock();
//		s2= calloc(count,size);
//		end_clock1 = clock();
//		printf("test time:%ld\n",end_clock1-start_clock1);
//		while(max--)
//		{
//			if(s2[max] != 0)
//				printf("error s2\n");
//		}
//
//
//		start_clock2 = clock();
//		s1= ft_calloc(count,size);
//		end_clock2 = clock();
//		printf("my time:%ld\n",end_clock2-start_clock2);
//
//		max = count*size;
//		while(max--)
//		{
//			if(s1[max] != 0)
//				printf("error s1\n");
//		}
//	}
//	return (0);
//}
