/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:58:17 by hsano             #+#    #+#             */
/*   Updated: 2022/07/14 20:21:33 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_c(char const *s, char c)
{
	size_t	i;
	size_t	cnt;
	int		flag;

	i = 0;
	cnt = 0;
	flag = true;
	if (c == '\0')
		return (1);
	while (s[i])
	{
		if (s[i] == c)
			flag = true;
		else if (flag == true)
		{
			flag = false;
			cnt++;
		}
		i++;
	}
	return (cnt);
}

static char	*write_array(char const *s, size_t diff, size_t i)
{
	char	*p;

	p = malloc(diff + 1);
	p[diff] = '\0';
	while (diff--)
		p[diff] = s[i + diff];
	return (p);
}

static char	**make_array(char **p, char const *s, int c, size_t cnt)
{
	char	*tmp_p;
	size_t	i;
	size_t	j;
	size_t	diff;

	j = 0;
	i = 0;
	while (j < cnt)
	{
		tmp_p = ft_strchr(&(s[i]), c);
		if (tmp_p == NULL)
			break ;
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

static char	**allocate_memmory(size_t cnt)
{
	char	**p;

	p = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (p == NULL)
		return (NULL);
	p[cnt] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	cnt;

	if (s == NULL || s[0] == '\0')
		return (allocate_memmory(0));
	cnt = count_c(s, c);
	p = allocate_memmory(cnt);
	if (p == NULL)
		return (NULL);
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
//	size = 2;
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
//	char *tmp = "\0aa\0bbb";
//	printf("test No.2:%s:end\n",tmp);
//	char	*s = "      split       this for   me  !       ";
//	char	**expected = ft_split(s , ' ');
//	printf("test No.3:%s:end\n",tmp);
//
//	i = 0;
//	size = 5;
//	while(i < size)
//	{
//		if (expected[i] == NULL)
//			break;
//		printf("e[%zu]=%s\n",i,expected[i]);
//		i++;
//	}
//	return (0);
//}
