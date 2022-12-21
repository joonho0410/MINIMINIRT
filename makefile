NAME	= miniRT
CC		= cc -g
# CFLAG	= -O3 -Werror -Wall -Wextra
CFLAG	= -Werror -Wall -Wextra
FFLAG	= -framework OpenGL -framework AppKit
SRCS 	=	./srcs/canvas.c\
			./srcs/hit_sphere.c\
			./srcs/hit.c\
			./srcs/mlx_set/mlx_window.c\
			./srcs/mlx_set/mlx_window_error.c\
			./srcs/normal.c\
			./srcs/object_create.c\
			./srcs/object_utils.c\
			./srcs/parse/parse_basic_validation_check.c\
			./srcs/parse/parse_error.c\
			./srcs/parse/parse_file.c\
			./srcs/parse/parse_line_object.c\
			./srcs/parse/parse_line_set.c\
			./srcs/parse/parse_line_utils1.c\
			./srcs/parse/parse_line_utils2.c\
			./srcs/parse/parse_line_validation_check.c\
			./srcs/parse/parse_util_string.c\
			./srcs/parse/parse_util1.c\
			./srcs/parse/parse_util2.c\
			./srcs/parse/parse_util3.c\
			./srcs/parse/parsing.c\
			./srcs/parse/set_scene.c\
			./srcs/phong_lighting.c\
			./srcs/print.c\
			./srcs/ray.c\
			./srcs/rotate.c\
			./srcs/scene.c\
			./srcs/main.c\
			./srcs/utils.c\
			./srcs/key.c

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