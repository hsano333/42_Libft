/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:36:03 by hsano             #+#    #+#             */
/*   Updated: 2022/07/12 13:21:57 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);

size_t	count_word(char *s1, char *set)
{
	size_t	count;
	size_t	i;
	size_t	k;
	size_t	len;

	count = 0;
	i = 0;
	k = 0;
	len = ft_strlen(set);
	if (len == 0)
		return (0);
	while (s1[i])
	{
		if (len == k)
		{
			count++;
			k = 0;
		}
		if (s1[i] == set[k])
			k++;
		else if (k > 0)
			k = 0;
		i++;
	}
	return (count);
}

char	*get_p(char *s1, char *set, size_t *len)
{
	size_t	count;
	size_t	size;
	char	*p;

	*len = ft_strlen(set);
	count = count_word(s1, set);
	size = ft_strlen(s1) - ft_strlen(set) * count;
	p = malloc(size);
	p[size] = '\0';
	return (p);
}

void	init_argv(size_t *i, size_t *j, size_t *k)
{
	*i = 0;
	*j = 0;
	*k = (size_t) - 1;
}

size_t	clear_j(size_t j, size_t len)
{
	if (len == j)
		j = 0;
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;

	p = get_p((char *)s1, (char *)set, &len);
	init_argv(&i, &j, &k);
	while (s1[++k])
	{
		if (s1[k] == set[j])
			j++;
		else
		{
			i += j;
			while (j--)
				p[i - j - 1] = set[j];
			p[i++] = s1[k];
			j = 0;
		}
		j = clear_j(j, len);
	}
	while (j--)
		p[i + j] = set[j];
	return (p);
}
int main(int argc, char **argv)
{

	char *p;
	if (argc == 3)
	{
		char	*s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
		char	*s2 = " \n\t";
		p = ft_strtrim(argv[1],argv[2]);
		printf("input1=%s,input2=%s\n",argv[1],argv[2]);
		printf("output=%s:end\n",p);
		p = ft_strtrim(s1,s2);
		printf("input1=%s,input2=%s\n",s1,s2);
		printf("output=%s:end\n",p);

	}
	return (0);
}
