/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:36:03 by hsano             #+#    #+#             */
/*   Updated: 2022/07/13 04:07:00 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);

size_t	count_word(char *s1, char *set, size_t k, size_t last)
{
	size_t	count;
	size_t	i;
	size_t	j;
	size_t	len;
	//size_t	tmp;

	count = 0;
	i = k;
	j = 0;
	//tmp = 0;
	len = ft_strlen(set);
	printf("strt i=%zu,last=%zu\n",i,last);
	while (i <= last)
	{
		//if (s1[i] <= ' ' || s1[i] >= 0x7f)
			//tmp++;
		//else
		//{
			//tmp = 0;
		if (s1[i] == set[j])
			j++;
		else if (j > 0)
			j = 0;
		if (len == j)
		{
			count++;
			j = 0;
		}
		//}
		i++;
	}
	return (i - k - count * len);
}

char	*get_p(char *s1, char *set, size_t *len, size_t *k)
{
	char	*p;
	size_t	last;

	*k = 0;
	last = ft_strlen(s1);
	while ((s1[*k] <= ' ' || s1[*k] >= 0x7f) && s1[*k] != '\0')
		(*k)++;
	while ((s1[last] <= ' ' || s1[last] >= 0x7f) && last > *k)
		last--;
	*len = count_word(s1, set, *k, last);
	printf("len=%zu\n",*len);
	p = malloc(*len + 1);
	if (!p)
		return (NULL);
	p[*len] = '\0';
	(*k)--;
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
	size_t	j;
	size_t	k;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	p = get_p((char *)s1, (char *)set, &len, &k);
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	if (len == 0 || p == NULL)
		return (p);
	len--;
	while (i < len)
	{
		k++;
		if (s1[k] == set[j])
			j++;
		else
		{
			i += write_not_match(p, i, &j, (char *)set);
			p[i++] = s1[k];
		}
		if (ft_strlen(set) == j)
			j = 0;
	}
	write_not_match(p, i, &j, (char *)set);
	return (p);
}
int main(int argc, char **argv)
{

	char *p;
	if (argc == 3)
	{
		char	*s1 = "  \t \t \n   \n\n\n\t";
		char	*s3 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !";
		char	*s2 = " \n\t";
		p = ft_strtrim(argv[1],argv[2]);
		//printf("input1=%s,input2=%s\n",argv[1],argv[2]);
		printf("test1:output=%s:end\n",p);
		
		p = ft_strtrim(s1,s2);
		//printf("input1=%s,input2=%s\n",s1,s2);
		printf("test2:output=%s:end\n",p);
		p = ft_strtrim(s3,s2);
		printf("test3:output=%s:end\n",p);

	}
	return (0);
}
