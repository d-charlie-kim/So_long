# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 18:38:34 by jaejeong          #+#    #+#              #
#    Updated: 2021/07/25 09:08:50 by dokkim           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
OS			= Mac

CC			= gcc
CFLAGS		= $(INCFLAGS) $(GFLAGS) # $(WFLAGS)
WFLAGS		= -Wall -Wextra -Werror
GFLAGS		= -g -fsanitize=address

ifeq ($(OS), Linux)
	MLXFLAGS = -lmlx -lbsd -lXext -lX11
else
	MLXFLAGS = -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit
endif

INCDIR		= include
MLXDIR		= minilibx_opengl_20191021
MLX			= $(MLXDIR)/libmlx.a

SRCS		= ./so_long.c\
			  ./draw/draw.c\
			  ./get_next_line/get_next_line.c\
			  ./get_next_line/get_next_line_utils.c\
			  ./map/map_check.c\
			  ./map/map_utils.c\
			  ./map/mapping.c\

OBJS	= $(SRCS:.c=.o)

all			: $(NAME)

$(NAME)		: $(MLX) $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) $(MLXFLAGS)

$(MLX)		:
	make -C $(MLXDIR) all

clean		:
	$(RM) $(OBJS)

fclean		: clean
	$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
