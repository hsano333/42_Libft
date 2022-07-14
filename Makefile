CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I ${HEAD}
NAME 	= libft.a
PRE		= ./
HEAD	= ./
SRC		= ft_strnstr.c ft_isdigit.c ft_putstr_fd.c ft_strlcpy.c ft_strlen.c ft_memcmp.c ft_putnbr_fd.c ft_strchr.c ft_striteri.c ft_bzero.c ft_strjoin.c ft_isascii.c ft_memcpy.c ft_isprint.c ft_putendl_fd.c ft_substr.c ft_toupper.c ft_split.c ft_strrchr.c ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_memset.c ft_strncmp.c ft_strmapi.c ft_strtrim.c ft_memmove.c ft_strlcat.c ft_calloc.c ft_strdup.c ft_atoi.c ft_isalnum.c ft_itoa.c ft_tolower.c
BSRC	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
ifdef WITH_BONUS
SRC += $(BSRC)
endif
SRCS	= ${addprefix ${PRE}, ${SRC}}
OBJS	= $(SRCS:.c=.o)
BSRCS	= ${addprefix ${PRE}, ${BSRC}}
BOBJS	= $(BSRCS:.c=.o)

all:	${NAME}

${NAME}	:	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean	:
			${RM} ${OBJS}
			${RM} ${BOBJS}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

bonus	:	
			make WITH_BONUS=1
			
