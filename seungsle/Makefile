# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 10:49:53 by junhjeon          #+#    #+#              #
#    Updated: 2022/12/14 21:32:43 by seungsle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = 
#-Wall -Wextra -Werror
SRC_DIR = .
NAME = test
SRCS = ./main.c ./print.c ./canvas.c ./ray.c ./scene.c ./utils.c ./object_create.c ./hit_sphere.c
OBJS = $(SRCS:.c=.o)
INCLUDE = ../mlx

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
