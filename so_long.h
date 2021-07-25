/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:46:27 by dokkim            #+#    #+#             */
/*   Updated: 2021/07/25 09:16:50 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "./minilibx_mms_20200219/mlx.h"

typedef struct s_map
{
	char		*line;
	long long	width;
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
}	t_map_member;

int	ft_strlen(char *str);	
void	ft_strcmp(char *str, char *str2);
void	ft_putstr(char *str, int fd);
void	ft_error(char *str);

void	ft_lst_add(t_map **lst);
void	mapping(char **argv, t_map **so_map, t_map_member *map_member);
void	map_validate(t_map **so_map, char **argv, t_map_member *map_member);

void	map_member_init(t_map_member *map_member);
void	put_map_member(t_map_member *map_member, t_map **so_map);
void	map_is_rectangular(t_map_member	*map_member, t_map **so_map);
void	map_is_surrounded(t_map_member *map_member, t_map **so_map);
void	map_is_valid(t_map_member *map_member);

void draw(t_map **so_map, t_map_member *map_member);

#endif