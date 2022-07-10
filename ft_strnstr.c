/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:37:16 by hsano             #+#    #+#             */
/*   Updated: 2022/07/10 14:41:00 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int	k;
	int len_n;

	i = 0;
	k = 0;
	len_n = 0;
	while(((char *)needle)[len_n])
		len_n++;
	printf("len=%zu\n",len);
	while (i < len)
	{
		if (len_n == k)
			return &(((char *)haystack)[i-len_n]);
		else if (haystack[i] == needle[k])
			k++;
		else
			k = 0;
		i++;
	}
	if (len_n == k)
		return &(((char *)haystack)[i-len_n]);
	return (0);
}
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int main(int argc,char **argv)
//{
//	char *s1;
//	char *s2;
//	char *result;
//	size_t		len;
//	if (argc == 4)
//	{
//		s1 = argv[1];
//		s2 = argv[2];
//		len = atoi(argv[3]);
//		result = ft_strnstr(s1,s2,len);
//		printf("s1=%s,s2=%s,len=%zu\n",s1,s2,len);
//		printf("result=%s\n",result);
//		result = strnstr(s1,s2,len);
//		printf("result=%s\n",result);
//
//	}
//	return (0);
//}
