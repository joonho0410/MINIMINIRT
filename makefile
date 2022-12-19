# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 10:49:53 by junhjeon          #+#    #+#              #
#    Updated: 2022/12/19 09:27:54 by seungsle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g
CFLAGS = 
#-Wall -Wextra -Werror
SRC_DIR = .
NAME = so_long
SRCS = ./test.c ./print.c ./utils.c ./canvas.c ./scene.c ./ray.c ./object_create.c ./hit_sphere.c \
	   ./normal.c\
	   ./object_utils.c\
	   ./hit.c\
	   ./phong_lighting.c\
	   ./rotate.c\
	   ./parsing.c\
	   ./parsing_utils.c
OBJS = $(SRCS:.c=.o)
INCLUDE = ./mlx

all : $(NAME)
		
.c.o:
	$(CC) -c $(CFLAGS) -I $(INCLUDE) -o $@ $< 

$(NAME) : $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $(OBJS)

#-L./mlx -lmlx  -framework OpenGL -framework Appkit 

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re
