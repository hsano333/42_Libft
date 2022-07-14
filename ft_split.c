/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:58:17 by hsano             #+#    #+#             */
/*   Updated: 2022/07/14 15:12:13 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_c(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	if (c == '\0')
		return (cnt);
	while (s[i])
	{
		if (s[i] == c)
			cnt++;
		i++;
	}
	if (s[i - 1] != c && i > 0)
		cnt++;
	if (s[0] == c && cnt > 0)
		cnt--;
	return (cnt);
}

void	write_array(char *p, char const *s, char *tmp_p, size_t i)
{
	size_t	diff;

	diff = tmp_p - &(s[i]);
	printf("diff=%zu,tmp_p=%s\n",diff,tmp_p);
	p = malloc(diff + 1);
	p[diff] = '\0';
	while(diff--)
		p[diff] = s[i + diff];

}

char	**make_array(char **p, char const *s, int c, size_t cnt)
{
	char	*tmp_p;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	p[cnt] = NULL;
	tmp_p = ft_strchr(&(s[i]), c);
	while(tmp_p != NULL)
	{
		write_array(&(p[j][0]), s, tmp_p, i);
		i += tmp_p - &(s[i]) + 1;
		printf("i=%zu\n",i);
		tmp_p = ft_strchr(&(s[i]), c);
		j++;
	}
	printf("end loop\n");
	tmp_p = &(s[ft_strlen(s)]);
	write_array(&(p[j][0]), s, tmp_p, i);
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	cnt;

	printf("test No.1\n");
	cnt = count_c(s, c);
	printf("test No.2 cnt=%zu\n",cnt);
	p = (char **)malloc(sizeof(char *) * (cnt + 1));
	printf("test No.3\n");
	p = make_array(p, s, (int)c, cnt);
	printf("test No.4\n");
	return (p);
}
int main(int argc, char **argv)
{

	char **p;
	char c;
	size_t	size;
	size_t i;

	i = 0;
	if (argc == 4)
	{
		/*
		char	*s1 = "  \t \t \n   \n\n\n\t";
		char	*s3 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !";
		char	*s2 = " \n\t";
		*/
		c = argv[2][0];
		p = ft_split(argv[1],c);
		size = atoi(argv[2]);
		while(i < size)
		{
			printf("p[%zu]=%s\n",i,p[i]);
			i++;
		}

	}
	return (0);
}
