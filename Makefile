NAME	=	Wolf3D

SRCS	=	main.c
SRCS	+=	color.c
SRCS	+=	map.c
SRCS	+=	init.c
SRCS	+=	debug.c


SRC		=	$(addprefix srcs/, $(SRCS))

OBJ			=	$(SRC:.c=.o)

HEADER	=	includes/wolf3d.h
HEADER	+=	libft/libft.h
HEADER	+=	Makefile

LIB		=	libft/libft.a

RM		=	rm -f

CC		=	clang

CFLAGS	=	-Wall -Wextra -I./libft/ -I./includes
#CFLAGS	+= -Werror
LDFLAGS	=	-L./libft/ -lft -lm

SYS		:=	$(shell uname)

ifeq ($(SYS), Darwin)
  CFLAGS	+=	-I./includes/MacOs -I./minilibx_macos/
  LDFLAGS	+=	-framework OpenGL -framework AppKit -L./minilibx_macos -lmlx
  MLX		= minilibx_macos/libmlx.a
else
  CFLAGS	+= -I./includes/Linux -I./minilibx_linux
  LDFLAGS +=	-lXext -lX11 -L./minilibx_linux -lmlx_Linux -lpthread  -D_REENTRANT -DLinux
  MLX		= minilib_linux/libmlx.a
endif

%.o : %.c $(HEADER)
		$(CC) -o $@ -c $< $(CFLAGS)

all : $(NAME)

$(NAME) : $(LIB) $(OBJ)
		@echo "Compiled for $(SYS)"
		@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

$(LIB)	:
		make -C libft/

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re	:	fclean all

lib		:
		make -C libft/

cleanlib :
		make -C libft/ fclean

relib : fclean cleanlib lib all


.PHONY	: clean fclean re
