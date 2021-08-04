# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 18:38:34 by jaejeong          #+#    #+#              #
#    Updated: 2021/08/04 16:06:46 by dokkim           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
OS			= Mac

CC			= gcc
CFLAGS		= $(INCFLAGS) $(GFLAGS) -g -fsanitize=address # $(WFLAGS)
WFLAGS		= -Wall -Wextra -Werror
GFLAGS		= -g -fsanitize=address
INC			= -I ./includes

ifeq ($(OS), Linux)
	MLXFLAGS = -lmlx -lbsd -lXext -lX11
else
	MLXFLAGS = -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit
endif

MLXDIR		= minilibx_opengl_20191021
MLX			= $(MLXDIR)/libmlx.a

GNL_SRCS		= $(addprefix ./srcs/get_next_line/, \
					get_next_line.c \
					get_next_line_utils.c \
					)

DRAW_SRCS		= $(addprefix ./srcs/draw/, \
					draw_contents.c \
					draw_first.c \
					draw_update.c \
					get_images.c \
					)

LOOP_SRCS		= $(addprefix ./srcs/loop/, \
					sprite.c \
					)

MAP_SRCS		= $(addprefix ./srcs/map/, \
					mapping.c \
					)

MOVE_SRCS		= $(addprefix ./srcs/move/, \
					move_left.c \
					move_right.c \
					move_up.c \
					move_down.c \
					move.c \
					move_mapping.c \
					)

UTILS_SRCS		= $(addprefix ./srcs/utils/, \
					init.c \
					key_hook.c \
					utils_map.c \
					utils.c \
					)

VALIDATE_SRCS	= $(addprefix ./srcs/validate/, \
					map_validate.c \
					)

SRCS		= ./srcs/main.c \
				$(DRAW_SRCS) \
				$(GNL_SRCS) \
				$(LOOP_SRCS) \
				$(MAP_SRCS) \
				$(MOVE_SRCS) \
				$(UTILS_SRCS) \
				$(VALIDATE_SRCS) \

OBJS	= $(SRCS:.c=.o)

%.o		:	%.c
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

all			: $(NAME)

$(NAME)		: $(MLX) $(OBJS)
	$(CC) $(OBJS) $(INC) $(CFLAGS) $(MLXFLAGS) -o $@

$(MLX)		:
	make -C $(MLXDIR) all

clean		:
	$(RM) $(OBJS)

fclean		: clean
	$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
