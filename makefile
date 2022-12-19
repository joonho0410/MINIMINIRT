NAME	= fractol
CC		= cc -g
# CFLAG	= -O3 -Werror -Wall -Wextra
CFLAG	= -Werror -Wall -Wextra
FFLAG	= -framework OpenGL -framework AppKit
SRCS 	=	./canvas.c\
			./hit_sphere.c\
			./hit.c\
			./mlx_window.c\
			./normal.c\
			./object_create.c\
			./object_utils.c\
			./parsing_utils.c\
			./parsing.c\
			./phong_lighting.c\
			./print.c\
			./ray.c\
			./rotate.c\
			./scene.c\
			./test.c\
			./utils.c

OBJS 	= ${SRCS:.c=.o}
INCLUDE	= -I./includes/ -L./mlx -lmlx

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) $(INCLUDE) $(FFLAG) -o $(NAME)

.c.o:
	$(CC) $(CFLAG) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re