/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:58:17 by hsano             #+#    #+#             */
/*   Updated: 2022/07/14 15:59:50 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_c(char const *s, char c)
{
	size_t	i;
	size_t	cnt;
	int	flag;

	i = 0;
	cnt = 0;
	flag = TRUE;
	if (c == '\0')
		return (1);
	while (s[i])
	{
		if (s[i] == c)
			flag = TRUE;
		else if(flag == TRUE)
		{
			flag = FALSE;
			cnt++;
		}
		i++;
	}
	return (cnt);
}

char	*write_array(char const *s, size_t diff, size_t i)
{
	char	*p;

	p = malloc(diff + 1);
	p[diff] = '\0';
	while(diff--)
		p[diff] = s[i + diff];
	return (p);

}

char	**make_array(char **p, char const *s, int c, size_t cnt)
{
	char	*tmp_p;
	size_t	i;
	size_t	j;
	size_t	diff;

	j = 0;
	i = 0;
	while(j < cnt)
	{
		tmp_p = ft_strchr(&(s[i]), c);
		if (tmp_p == NULL)
			break;
		diff = tmp_p - &(s[i]);
		if (diff > 0)
			p[j++] = write_array(s, diff, i);
		i += diff + 1;
	}
	diff = ft_strlen(s) - i;
	if (j < cnt)
		p[j] = write_array(s, diff, i);
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	cnt;

	cnt = count_c(s, c);
	p = (char **)malloc(sizeof(char *) * (cnt + 1));
	p[cnt] = NULL;
	p = make_array(p, s, (int)c, cnt);
	return (p);
}
//int main(int argc, char **argv)
//{
//
//	char **p;
//	char c;
//	size_t	size;
//	size_t i;
//
//	i = 0;
//	if (argc == 4)
//	{
//		c = argv[2][0];
//		p = ft_split(argv[1],c);
//		size = atoi(argv[3]);
//		while(i < size)
//		{
//			printf("p[%zu]=%s\n",i,p[i]);
//			i++;
//		}
//
//	}
//	return (0);
//}
