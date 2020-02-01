# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: padelord <padelord@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 18:58:28 by padelord          #+#    #+#              #
#    Updated: 2019/10/09 17:26:40 by padelord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC	=	gcc

SRCPATH	=	./

SRCPART1=	ft_memset.c			\
			ft_bzero.c			\
			ft_memcpy.c			\
			ft_memccpy.c		\
			ft_memmove.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_strlen.c			\
			ft_strdup.c			\
			ft_strcpy.c			\
			ft_strncpy.c		\
			ft_strcat.c			\
			ft_strncat.c		\
			ft_strlcat.c		\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strstr.c			\
			ft_strnstr.c		\
			ft_strcmp.c			\
			ft_strncmp.c		\
			ft_atoi.c			\
			ft_isalpha.c		\
			ft_isdigit.c		\
			ft_isalnum.c		\
			ft_isascii.c		\
			ft_isprint.c		\
			ft_toupper.c		\
			ft_tolower.c

SRCPART2=	ft_memalloc.c		\
			ft_memdel.c			\
			ft_strnew.c			\
			ft_strdel.c			\
			ft_strclr.c			\
			ft_striter.c		\
			ft_striteri.c		\
			ft_strmap.c			\
			ft_strmapi.c		\
			ft_strequ.c			\
			ft_strnequ.c		\
			ft_strsub.c			\
			ft_strjoin.c		\
			ft_strtrim.c		\
			ft_strsplit.c		\
			ft_itoa.c			\
			ft_putchar.c		\
			ft_putstr.c			\
			ft_putendl.c		\
			ft_putnbr.c			\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c

SRCBONUS=	ft_lstnew.c			\
			ft_lstdelone.c		\
			ft_lstdel.c			\
			ft_lstadd.c			\
			ft_lstiter.c		\
			ft_lstmap.c			\
			ft_isspace.c		\
			ft_putstr_color.c	\
			ft_putendl_color.c	\
			ft_strrev.c			\
			ft_cswap.c			\
			ft_iswspace.c		\
			ft_staticitoa.c		\
			ft_memdup.c			\
			ft_min.c			\
			ft_putnchar.c		\
			ft_putnstr.c		\
			ft_lstpback.c		\
			ft_putnbrendl.c		\
			ft_wtabdel.c		\
			ft_putwordtab.c		\
			ft_lstgetsize.c		\
			ft_lsttostr.c		\
			ft_displstr.c		\
			ft_strocontent.c	\
			ft_lstbasicdel.c	\
			ft_sqrti.c

SRCNAME	=	$(SRCPART1)			\
			$(SRCPART2)			\
			$(SRCBONUS)

SRCS	=	$(addprefix $(SRCPATH), $(SRCNAME))

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I./

HEADERS = libft.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@echo "Deleted libft objects"

fclean:	clean
	@rm -f $(NAME)
	@echo "Deleted $(NAME)"

re:	fclean all
