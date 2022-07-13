/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:36:03 by hsano             #+#    #+#             */
/*   Updated: 2022/07/13 16:55:01 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	count_word(const char *s1, const char *set, size_t k, size_t last)
{
	size_t	count;
	size_t	i;
	size_t	j;
	size_t	len;

	count = 0;
	i = k - 1;
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
	return (i - k - count * len);
}

size_t	check_last_word(const char *s1, const char *set, size_t last)
{
	size_t	len;
	size_t	diff;
	size_t	i;

	diff = 0;
	len = ft_strlen(set);

	i = last - len;
	if(!ft_strncmp(&(s1[i]), set, len))
	{
		while ((s1[i] <= ' ' || s1[i] >= 0x7f) && last > 0)
		{
			i--;
			diff++;
		}
	}
	printf("diff=%zu\n",diff);
	return (diff);
}

char	*get_p(const char *s1, const char *set, size_t *len, size_t *k)
{
	char	*p;
	size_t	last;
	size_t	diff;

	*k = 0;
	last = ft_strlen(s1);
	if (s1 == NULL)
		return (NULL);
	while ((s1[*k] <= ' ' || s1[*k] >= 0x7f) && s1[*k] != '\0')
		(*k)++;
	while ((s1[last] <= ' ' || s1[last] >= 0x7f) && last > *k)
		last--;
	*len = count_word(s1, set, *k, last);
	diff = check_last_word(s1, set, last);
	*len -= diff;
	printf("len=%zu\n",*len);
	/*
	if (*len == 0)
		p = malloc(*len + 1);
	else
		p = malloc(*len);
	*/
	p = malloc(*len + 1);
	if (p == NULL)
	{
		*len = 0;
		return (NULL);
	}
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

//char	*trim(char *p, char const *s1, char const *set, size_t len)
/*
char	*trim(char const *s1, char const *set, size_t s1_len, size_t set_len)
{
	char	*p;
	char	*tmp;
	size_t	i;
	size_t	j;

	p = malloc(s1_len);
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	while ((s1[i] <= ' ' || 0x7f <= s1[i]) && s1[i] != '\0')
		i++;
	while (i < s1_len)
	{
		tmp = ft_strnstr(&(s1[i]), set, s1_len - i);
		if (tmp == NULL)
			break ;
		while (tmp != NULL and &(s1[i]) == &(tmp[0]))
			p[j++] = s1[i++];
		i += set_len;
	}
	return (p);

	i = 0;
	j = 0;
	while (i < (len - 1))
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

}
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	/*
	char	*t;
	char	*s;
	size_t	s1_len;
	size_t	set_len;

	s1_len = ft_strlen(s1);
	set_len = ft_strlen(set);
	t = trim(s1, set, s1_len, set_len);

	free(t);
	*/
	char	*p;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;

	p = get_p(s1, set, &len, &k);
	if (len == 0)
		return (p);
	//trim(p, s1, set, len);
	i = 0;
	j = 0;
	while (i < (len - 1))
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
	printf("i=%zu,k=%zu\n",i,k);
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
