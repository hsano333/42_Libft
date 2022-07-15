/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:42:24 by hsano             #+#    #+#             */
/*   Updated: 2022/07/16 04:25:48 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digit_len(const char *str, size_t i)
{
	size_t	len;

	len = i;
	while (str[len])
	{
		if ('0' <= str[len] && str[len] <= '9')
			len++;
		else
			break ;
	}
	return (len - i);
}

static size_t	get_start_index(const char *str, int *minus)
{
	size_t	i;

	i = 0;
	*minus = 1;
	while (true)
	{
		if (str[i] == ' ' || (0x09 <= str[i] && str[i] <= 0x0D))
			i++;
		else
		{
			if (str[i] == '+')
				i++;
			else if (str[i] == '-')
			{
				i++;
				*minus = -1;
			}
			break ;
		}
	}
	return (i);
}

static unsigned long	ft_iterative_power(long nb, long power)
{
	long	rval;
	long	old;

	rval = (long)nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 0)
		return (0);
	while (--power)
	{
		old = rval;
		rval = nb * rval;
		if (old > rval)
			return (LONG_MAX);
	}
	return (rval);
}

int	ft_atoi(const char *str)
{
	int				minus;
	size_t			len;
	size_t			i;
	unsigned long	sum;
	unsigned long	a;

	i = get_start_index(str, &minus);
	sum = 0;
	len = get_digit_len(str, i);
	if (len == 0)
		return (0);
	a = ft_iterative_power(10, len - 1);
	while (a > 0)
	{
		sum += (str[i++] - '0') * a;
		if (sum > LONG_MAX)
		{
			if (minus == -1 || sum == (LONG_MAX))
				return (0);
			else
				return (-1);
		}
		a /= 10;
	}
	return ((int)(sum * minus));
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
//	printf("LONGMAX=%ld\n",LONG_MAX);
//	if (argc == 2)
//	{
//		s1 = argv[1];
//		//s1 = "\t\v\f\r\n \f-06050";
//		len = atoi(s1);
//		result = ft_atoi(s1);
//		printf("input:%s\n",s1);
//		printf("my:%d\n",result);
//		printf("test:%d\n",len);
//
//	}
//	return (0);
//}
