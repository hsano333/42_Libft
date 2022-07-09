/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:40:57 by hsano             #+#    #+#             */
/*   Updated: 2022/07/09 12:55:47 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# include <stdlib.h>
//# include <errno.h>
//# include <fcntl.h>
//# include <unistd.h>

//# define SIZE 256
# define TRUE 1
# define FALSE 0
//# define ERROR1 "File name missing.\n"
//# define ERROR2 "*content of file Makefile*\n"
//# define ERROR3 "Too many arguments.\n"
//# define MAKEFILE "Makefile"

//void	ft_display_file(char *filepath);
//void	ft_putstr(char *str);
//int		ft_strcmp(char *s1, char *s2);
//int		ft_strcmp(char *s1, char *s2);
//void	ft_putchar(char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
        	
size_t	ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
size_t	ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
size_t	ft_strlen(const char *s);
	        	
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
     
     	 
     
	      
	      

	      
#endif
