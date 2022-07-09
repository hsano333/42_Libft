/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:45:16 by hsano             #+#    #+#             */
/*   Updated: 2022/07/09 18:10:48 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;


	i = 0;
	while (i < n)
	{
		if (((char*)s1)[i] != ((char*)s2)[i])
			return (((char*)s1)[i] - ((char*)s2)[i]);
		i++;
	}
	return (0);
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
//		result = ft_memcmp(s1,s2,len);
//		printf("s1=%s,s2=%s,len=%zu\n",s1,s2,len);
//		printf("result=%d\n",result);
//		result = memcmp(s1,s2,len);
//		printf("result=%d\n",result);
//
//	}
//	return (0);
//}
