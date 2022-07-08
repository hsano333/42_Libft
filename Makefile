CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME 	= libft.a
PRE		= .
HEAD	= .
SRC		= ft_strnstr.c ft_isdigit.c ft_putstr_fd.c ft_strlcpy.c ft_strlen.c ft_memcmp.c ft_putnbr_fd.c ft_strchr.c ft_striteri.c ft_bzero.c ft_strjoin.c ft_isascii.c ft_memcpy.c ft_isprint.c ft_putendl_fd.c ft_ft_substr.c ft_toupper.c ft_split.c ft_strrchr.c ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_memset.c ft_strncmp.c ft_strmapi.c ft_strtrim.c ft_memmove.c ft_strlcat.c ft_calloc.c ft_strdup.c ft_atoi.c ft_isalnum.c ft_itoa.c ft_tolower.c
SRCS	= ${addprefix ${PRE}, ${SRC}}
OBJS	= $(SRCS:.c=.o)

all:	${NAME}

${NAME}	:	${OBJS}
			ar rcs ${NAME} ${OBJS}

.c.o:
			${CC} ${CFLAGS} -I ${HEAD} -c $^ -o $@

clean	:
			${RM} ${OBJS}
			${RM} ${NAME}

fclean	:	clean

re		:	fclean all
 