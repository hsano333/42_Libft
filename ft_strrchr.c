/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:55:56 by hsano             #+#    #+#             */
/*   Updated: 2022/07/09 14:54:11 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	while (*s)
		s++;
	s--;

	while (*s)
	{
		if (*s == c)
			return (char *)(s);
		s--;
	}
	return (0);
}
//#include <stdio.h>
//#include <string.h>
//int main(void)
//{
//	char test[] = "t1est12345";
//	char *p;
//	char *q;
//
//	p = ft_strrchr(test,'1');
//	q = strrchr(test,'1');
//	printf("%s\n",p);
//	printf("%s\n",q);
//
//	p = ft_strrchr(test,'0');
//	q = strrchr(test,'0');
//	printf("%s\n",q);
//	printf("%s\n",p);
//	return (0);
//}
