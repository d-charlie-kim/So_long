/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:06:34 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/04 16:08:17 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_STRUCT_H
# define SO_STRUCT_H

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
	int	zero;
	int	collectable;
	int	player;
	int	exit;
	int	collect_count;
	int	walk_count;
	int	player_x;
	int	player_y;
	int	enemy_x;
	int	enemy_y;
}	t_map_member;

typedef struct s_images
{
	void	*mlx;
	void	*win;
	void	*wall1;
	void	*wall2;
	void	*road;
	void	*player;
	void	*collectable1;
	void	*collectable2;
	void	*collectable3;
	void	*enemy;
	void	*ballon;
	void	*ballon_effect;
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

#endif