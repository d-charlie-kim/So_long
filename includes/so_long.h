/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:46:27 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/03 21:32:57 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx_mms_20200219/mlx.h"

# include "so_keycode.h"
# include "so_struct.h"


// map
void	mapping(char **argv, t_data *data);
void	get_map(int fd, t_map **so_map);
void	put_map_member(t_map_member *map_member, t_map **so_map);

// validate
void	map_validate(t_data *data);
void	map_is_rectangular(t_map_member	*map_member, t_map **so_map);
void	map_is_surrounded(t_map_member *map_member, t_map **so_map);
void	first_last_line(char *str, int size);
void	map_is_valid(t_map_member map_member);

// first draw
void	draw(t_data *data);
void	draw_first(t_map **so_map, t_map_member *map_member, t_images *images);
void	draw_background(t_map_member *map_member, t_images *images);
void	draw_contents(t_map_member *map_member, t_images *images, int dy, char *line);

void	get_images(t_images *images, t_map_member *map_member);

// draw contents
void	draw_player(t_map_member *map_member, t_images *images, int dx, int dy);
void	draw_collectable(t_map_member *map_member, t_images *images, int dx, int dy);
void	draw_exit(t_map_member *map_member, t_images *images, int dx, int dy);
void	draw_wall(t_map_member *map_member, t_images *images, int dx, int dy);
// void	draw_enemy(t_map_member *map_member, t_images *images, int dx, int dy);

// key hook
int		x_icon(int keycode, t_data *data);

// utils
void	ft_strcmp(char *str, char *str2);
void	ft_error(char *str);
void	ft_lst_add(t_map **lst);

char	get_map_contents(t_data *data, int dx, int dy);

// utils_init
void	data_init(t_data *data);
void	map_member_init(t_map_member *map_member);
void	images_init(t_images *images);

// map update
void	change_map(t_data *data, int dx, int dy);

// player move
int		key_move(int keycode, t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);

// sprite animation loop
int		sprite_loop(t_data *data);

#endif
