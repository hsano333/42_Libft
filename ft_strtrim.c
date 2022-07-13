/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:36:03 by hsano             #+#    #+#             */
/*   Updated: 2022/07/14 05:07:32 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

size_t	count_word(const char *s1, const char *set, size_t begin, size_t last)
{
	size_t	count;
	size_t	i;
	size_t	j;
	size_t	len;

	count = 0;
	i = begin - 1;
	j = 0;
	len = ft_strlen(set);
	while (++i <= last)
	{
		if (s1[i] == set[j])
			j++;
		else if (j > 0)
		{
			i -= j;
			j = 0;
		}
		if (len == j)
		{
			count++;
			j = 0;
		}
	}
	return (i - begin - count * len);
}

void	get_index(const char *s1, const char *set, size_t *begin, size_t *last)
{
	size_t	set_len;
	char	*tmp_p;

	while ((s1[*begin] <= ' ' || s1[*begin] >= 0x7f) && s1[*begin] != '\0')
		(*begin)++;
	while ((s1[*last] <= ' ' || s1[*last] >= 0x7f) && *last > *begin)
		(*last)--;
	set_len = ft_strlen(set);
	tmp_p = ft_strnstr(&(s1[*begin]), set, set_len);
	while (tmp_p != NULL && tmp_p == &(s1[*begin]))
	{
		*begin += set_len;
		tmp_p = ft_strnstr(&(s1[*begin]), set, set_len);
	}
}

char	*get_p(const char *s1, const char *set, size_t *begin, size_t *last)
{
	char	*p;
	size_t	len;

	*begin = 0;
	*last = ft_strlen(s1);
	get_index(s1, set, begin, last);
	len = count_word(s1, set, *begin, *last);
	p = malloc(len + 1);
	if (p == NULL)
	{
		*begin = *last;
		return (NULL);
	}
	p[len] = '\0';
	return (p);
}

size_t	write_not_match(char *p, size_t i, size_t *j, char *set)
{
	size_t	cnt;

	cnt = 0;
	while ((*j)--)
	{
		p[i + *j] = set[*j];
		cnt++;
	}
	*j = 0;
	return (cnt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	i;
	size_t	b;
	size_t	l;
	char	*tmp_p;

	if (s1 == NULL)
		return (NULL);
	p = get_p(s1, set, &b, &l);
	if (l == b || p == NULL)
		return (p);
	i = 0;
	tmp_p = ft_strnstr(&(s1[b]), set, l - b + 1);
	while (tmp_p != NULL)
	{
		while (&(s1[b]) != tmp_p)
			p[i++] = s1[b++];
		b += ft_strlen(set);
		tmp_p = ft_strnstr(&(s1[b]), set, l - b + 1);
	}
	while (b <= l)
		p[i++] = s1[b++];
	return (p);
}
//int main(int argc, char **argv)
//{
//
//	char *p;
//	if (argc == 3)
//	{
//		/*
//		char	*s1 = "  \t \t \n   \n\n\n\t";
//		char	*s3 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !";
//		char	*s2 = " \n\t";
//		*/
//		p = ft_strtrim(argv[1],argv[2]);
//		//printf("input1=%s,input2=%s\n",argv[1],argv[2]);
//		printf("test1:output=%s:end\n",p);
//		
//		/*
//		p = ft_strtrim(s1,s2);
//		//printf("input1=%s,input2=%s\n",s1,s2);
//		printf("test2:output=%s:end\n",p);
//		p = ft_strtrim(s3,s2);
//		printf("test3:output=%s:end\n",p);
//		*/
//
//	}
//	return (0);
//}
