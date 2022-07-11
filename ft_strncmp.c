/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:46:01 by hsano             #+#    #+#             */
/*   Updated: 2022/07/12 00:58:06 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (s1[i] && s2[i] && (i < n))
	{
		if (us1[i] != us2[i])
			return ((int)(us1[i] - us2[i]));
		i++;
	}
	if (i == n)
		return (0);
	return ((int)(us1[i] - us2[i]));
}
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int main(int argc,char **argv)
//{
//	char *s1;
//	char *s2;
//	int 	result;
//	size_t		len;
//	if (argc == 4)
//	{
//		s1 = argv[1];
//		s2 = argv[2];
//		len = atoi(argv[3]);
//		result = ft_strncmp(s1,s2,len);
//		printf("s1=%s,s2=%s,len=%zu\n",s1,s2,len);
//		printf("result=%d\n",result);
//		result = strncmp(s1,s2,len);
//		printf("result=%d\n",result);
//
//	}
//	return (0);
//}
