/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:50:00 by hsano             #+#    #+#             */
/*   Updated: 2022/07/10 03:03:09 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(const char *s1)
{
	size_t		size;
	char	*p;

	size = ft_strlen(s1);
	p = (char *)malloc(size + 1);
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s1, size);
	p[size] = '\0';
	return (p);
}
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int main(int argc,char **argv)
//{
//	char *s1;
//	char *s2;
//	char *s3;
//	if (argc == 2)
//	{
//		s1 = argv[1];
//		s2 = ft_strdup(s1);
//		s3 = strdup(s1);
//		printf("s1=%s,my=%s,test=%s\n",s1,s2,s3);
//
//	}
//	return (0);
//}
