/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:36:03 by hsano             #+#    #+#             */
/*   Updated: 2022/07/12 16:23:43 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);

size_t	count_word(char *s1, char *set, size_t k)
{
	size_t	count;
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	tmp;

	count = 0;
	i = k;
	j = 0;
	tmp = 0;
	len = ft_strlen(set);
	if (len == 0)
		return (0);
	while (s1[i])
	{
		if (s1[i] <= ' ' || s1[i] >= 0x7f)
			tmp++;
		else
		{
			i+= tmp;
			tmp = 0;
			if (len == j)
			{
				count++;
				j = 0;
			}
			if (s1[i] == set[j])
				j++;
			else if (j > 0)
				j = 0;
		}
		i++;
	}
	return (i - k - tmp);
}

char	*get_p(char *s1, char *set, size_t *len, size_t *k)
{
	//size_t	count;
	//size_t	size;
	char	*p;

	//*len = ft_strlen(set);
	*k = 0;
	while ((s1[*k] <= ' ' || s1[*k] >= 0x7f) && s1[*k] != '\0')
		(*k)++;
	printf("k=%zu\n", *k);
	*len = count_word(s1, set, *k);
	printf("count=%zu\n",*len);
	//size = ft_strlen(s1) - ft_strlen(set) * (*len);
	p = malloc(*len + 1);
	p[*len] = '\0';
	(*k)--;
	return (p);
}

size_t	write_not_match(char *p, size_t i, size_t *j, char *set)
{
	int	cnt;

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

	printf("test No.1 \n");
	p = get_p((char *)s1, (char *)set, &len, &k);
	printf("test No.2 \n");
	i = 0;
	j = 0;
	while (i < len)
	{
		k++;
		//printf("test No.2 i=%zu,k=%zu\n",i,k);
		if (s1[k] == set[j])
			j++;
		else
		{
			//printf("test No.3 i=%zu,k=%zu,j=%zu\n",i,k,j);
			i += write_not_match(p, i, &j, (char *)set);
			//printf("test No.3-2 i=%zu,k=%zu\n",i,k);
			p[i++] = s1[k];
		}
		//printf("test No.4 i=%zu,k=%zu\n",i,k);
		if (ft_strlen(set) == j)
			j = 0;
		//printf("test No.5 i=%zu,k=%zu\n",i,k);
	}
	write_not_match(p, i, &j, (char *)set);
	return (p);
}
int main(int argc, char **argv)
{

	char *p;
	if (argc == 3)
	{
		char	*s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
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
