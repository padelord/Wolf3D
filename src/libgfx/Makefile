# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 14:13:30 by crenaudi          #+#    #+#              #
#    Updated: 2020/02/26 17:12:38 by padelord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgfx.a
AR = ar rc
CC = clang
RL = ranlib
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -c
SRC = ft_gfx.c		\
	  lerp.c				\
	  raddeg.c			\
		normalize.c		\
		product.c			\
		rotation.c		\
		img.c					\
		color_HSL.c 	\
		text_box.c		\
		camera.c		\
	  scale.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo		"\033[0;32m [OK] \033[0m       \033[0;33m Compiling: Libgfx.a\033[0m"
	@$(CC) $(CFLAGS) -g3 $(SRC) -I .
	@$(AR) $(NAME) $(OBJ)
	@$(RL) $(NAME)
	@echo		"\033[0;33m [LIBGFX][SUCCESS] \033[0m"

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
