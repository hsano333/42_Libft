/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:51:46 by hsano             #+#    #+#             */
/*   Updated: 2022/07/15 00:11:49 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_count(char *p, int n)
{
	long	a;
	size_t	i;	
	size_t	cnt;

	i = 0;
	cnt = 0;
	if (n < 0)
	{
		a = -1 * (long)n;
		cnt++;
	}
	else
		a = n;
	while (a)
	{
		p[i++] = (a % 10) + '0';
		a /= 10;
		cnt++;
	}
	if (n < 0)
		p[i++] = '-';
	return (cnt);
}

void	ft_itoa_no_memory(int n, char *p, char *r)
{
	size_t	i;
	size_t	cnt;

	if (n == 0)
	{
		r[0] = '0';
		r[1] = '\0';
		return (r);
	}
	cnt = get_count(p, n);
	r[cnt] = '\0';
	i = 0;
	while (i < cnt)
	{
		r[i] = p[cnt - i - 1];
		i++;
	}
	return (r);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	p[20];
	char	r[20];

	ft_itoa_no_memory(n, &(p[0]), &(r[0]));
	ft_putstr_fd(r, fd);
}
