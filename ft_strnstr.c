/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:37:16 by hsano             #+#    #+#             */
/*   Updated: 2022/07/14 06:08:13 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	is_equal(const char *str, const char *needle)
{
	size_t	i;

	i = 0;
	while (needle[i] && str[i])
	{
		if (str[i] != needle[i])
			return (FALSE);
		i++;
	}
	if (needle[i] == str[i])
		return (TRUE);
	return (FALSE);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_n;
	size_t	last;
	size_t	tmp;

	i = -1;
	len_n = ft_strlen(needle);
	last = ft_strlen(haystack);
	tmp = len_n;
	if (len_n == 0)
		return ((char *)haystack);
	if (len_n > last)
		return (NULL);
	while (i++ <= len - len_n)
	{
		if (haystack[i] == needle[0])
		{
			if (last - i <= len_n)
				tmp = last - i + 1;
			if (!ft_strncmp(&haystack[i], needle, tmp))
				return (&(((char *)haystack)[i]));
		}
	}
	return (NULL);
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
//		printf("my=%s\n",result);
//		result = strnstr(s1,s2,len);
//		printf("test=%s\n",result);
//
//	}
//	return (0);
//}
