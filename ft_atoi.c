/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:42:24 by hsano             #+#    #+#             */
/*   Updated: 2022/07/10 14:43:39 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len(char *str)
{
	int	i;

	i = 1;
	while(((char *)str)[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
			i++;
		else 
			break;
	}
	return (i);
}

int		ft_atoi(const char *str)
{
	int sum;
	int a;
	int	i;

	a = 1;
	sum = 0;
	i	= get_len((char *)str);
	while(--i > 0)
	{
		sum += (str[i] - '0') * a;
		a *= 10;
	}
	if (str[0] == '-')
		sum *= -1;
	else if('0' <= str[0] && str[0] <= '9')
		sum += (str[0] - 0x30) * a;
	else
		sum = 0;
	return (sum);
}
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int main(int argc,char **argv)
//{
//	char *s1;
//	int len;
//	int	result;
//
//	result = 0;
//	if (argc == 2)
//	{
//		s1 = argv[1];
//		len = atoi(s1);
//		result = ft_atoi(s1);
//		printf("input:%s\n",s1);
//		printf("my:%d\n",result);
//		printf("test:%d\n",len);
//
//	}
//	return (0);
//}
