/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:42:24 by hsano             #+#    #+#             */
/*   Updated: 2022/07/12 00:16:50 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_len(char *str)
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

char	*delete_blank(char *str)
{
	while(TRUE)
	{
		if (*str == ' ' || (*str >= 0x09 && *str <= 0x0D))
			str++;
		else
		{
			if (*str == '+')
				str++;
			break;
		}
	}
	return (str);
}

int		ft_atoi(const char *str)
{
	unsigned long	sum;
	unsigned long	old;
	long	a;
	size_t	i;
	char	*p;

	p = delete_blank((char *)str);
	a = 1;
	sum = 0;
	i= get_len((char *)p);
	while(--i > 0)
	{
		sum += (p[i] - '0') * a;
		a *= 10;
		if (sum > LONG_MAX)
		{
			if ((p[0] == '-') || (sum -1  == (LONG_MAX)))
			//return (0);
				return (0);
			else
				return (-1);
		}
	}
	if (p[0] == '-')
		sum *= -1;
	else if('0' <= p[0] && p[0] <= '9')
	{
		old = sum;
		sum += (p[0] - 0x30) * a;
		if (old > sum || sum > LONG_MAX)
			return (-1);
	}
	else
		return (0);
	return (int)(sum);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
	char *s1;
	int len;
	int	result;

	result = 0;
	printf("LONGMAX=%ld\n",LONG_MAX);
	if (argc == 2)
	{
		s1 = argv[1];
		//s1 = "\t\v\f\r\n \f-06050";
		len = atoi(s1);
		result = ft_atoi(s1);
		printf("input:%s\n",s1);
		printf("my:%d\n",result);
		printf("test:%d\n",len);

	}
	return (0);
}
