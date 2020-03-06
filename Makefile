# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 14:13:30 by crenaudi          #+#    #+#              #
#    Updated: 2020/03/03 19:58:03 by padelord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CC = clang
CFLAGS = -Wall -Wextra -O2
CFLAGS += -I./$(LIBGFX_FOLDER) -I./../includes/
MINILIBX = -I /usr/local/include/mlx.h -L /usr/local/lib/ -lmlx
FRAMEWORK = -lXext -lX11
LIB_MATH = -lm
THREAD = -lpthread
LIBFT_FOLDER = src/libft
LIB = -L./$(LIBFT_FOLDER) -lft
LIBFT = $(LIBFT_FOLDER)/libft.a
LIBGFX_FOLDER = src/libgfx
LIB2 = -L./$(LIBGFX_FOLDER) -lft
LIBGFX = $(LIBGFX_FOLDER)/gfx.a
RM = rm -f
SRC = src/main.c		\
		src/init.c		\
		src/raycast.c	\
		src/key.c		\
		src/parse.c		\
		src/legend.c	\
		src/clean.c		\
		src/error.c		\
		src/draw.c		\
		src/texture.c

OBJ = $(SRC:.c=.o)

%.o: %.c includes/wolf3d.h Makefile
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all fclean re

all: $(NAME)

$(LIBFT):
	@make -sC $(LIBFT_FOLDER)

$(LIBGFX):
	@make -sC $(LIBGFX_FOLDER)

$(NAME): $(OBJ) $(LIBFT) $(LIBGFX)
	@echo		"\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
	clang $(OBJ) -o $(NAME) -I./../includes/ -lm -lXext -lX11 -lmlx -L./src/libft/ -lft -L./src/libgfx/ -lgfx
	@echo		"\033[0;33m [FRACTOL][SUCCESS] \033[0m"

clean:
	@$(RM) $(OBJ)
	@make -sC $(LIBFT_FOLDER) clean
	@make -sC $(LIBGFX_FOLDER) clean
	@echo		"\033[0;34m [CLEAN][SUCCESS] \033[0m"

fclean: clean
	@$(RM) $(NAME)
	@make -sC $(LIBFT_FOLDER) fclean
	@make -sC $(LIBGFX_FOLDER) fclean
	@echo		"\033[0;34m [FCLEAN][SUCCESS] \033[0m"

re: fclean all
