/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:46:27 by dokkim            #+#    #+#             */
/*   Updated: 2021/07/30 18:35:29 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "./minilibx_mms_20200219/mlx.h"

# define ESC 53
# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define UP 13

typedef struct s_map
{
	char			*line;
	long long		width;
	struct s_map	*next;
	
}	t_map;

typedef struct s_map_member
{
	int	width;
	int	height;
	int zero;
	int collectable;
	int player;
	int exit;
	int	collect_count;
	int walk_count;
	int	player_x;
	int	player_y;
}	t_map_member;

typedef struct s_images
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*road;
	void	*player;
	void	*collectable1;
	void	*collectable2;
	void	*collectable3;
	void	*enemy;
	void	*exit;
	int		height;
	int		width;
}	t_images;

typedef struct s_data
{
	t_images		images;
	t_map_member	map_member;
	t_map			*so_map;
}	t_data;

int		ft_strlen(char *str);	
void	ft_strcmp(char *str, char *str2);
void	ft_putstr(char *str, int fd);
void	ft_error(char *str);

void	ft_lst_add(t_map **lst);
void	mapping(char **argv, t_map **so_map, t_map_member *map_member);
void	map_validate(t_map **so_map, char **argv, t_map_member *map_member);
void	images_init(t_images *images);
void	map_member_init(t_map_member *map_member);
void	put_map_member(t_map_member *map_member, t_map **so_map);
void	map_is_rectangular(t_map_member	*map_member, t_map **so_map);
void	map_is_surrounded(t_map_member *map_member, t_map **so_map);
void	map_is_valid(t_map_member *map_member);

void	draw(t_map **so_map, t_map_member *map_member, t_images *images);
void	draw_background(t_map **so_map, t_map_member *map_member, t_images *images);
void	draw_contents(t_map **so_map, t_map_member *map_member, t_images *images);
void	get_images(t_images *images, t_map_member *map_member);

int		move(int keycode, t_data *data);
void	move_left(t_data *data);
void	change_map(t_data *data, int dx, int dy);
char	get_map_contents(t_data *data, int dx, int dy);
void	move_right(t_data *data);
void	move_down(t_data *data);
void	move_up(t_data *data);

int		x_icon(int keycode, int x, int y, t_data *data);

#endif
