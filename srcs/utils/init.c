/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:36:27 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/03 21:16:52 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	data_init(t_data *data)
{
	map_member_init(&(data->map_member));
	images_init(&(data->images));
	data->so_map = NULL;
}

void	map_member_init(t_map_member *map_member)
{
	map_member->width = 0;
	map_member->height = 0;
	map_member->zero = 0;
	map_member->collectable = 0;
	map_member->player = 0;
	map_member->exit = 0;
	map_member->walk_count = 0;
	map_member->collect_count = 0;
	map_member->player_x = 0;
	map_member->player_y = 0;
	map_member->enemy_x = 0;
	map_member->enemy_y = 0;
}

void	images_init(t_images *images)
{
	images->mlx = NULL;
	images->win = NULL;
	images->wall1 = NULL;
	images->wall2 = NULL;
	images->road = NULL;
	images->player = NULL;
	images->collectable1 = NULL;
	images->collectable2 = NULL;
	images->collectable3 = NULL;
	images->enemy = NULL;
	images->ballon = NULL;
	images->ballon_effect = NULL;
	images->exit = NULL;
	images->height = 0;
	images->width = 0;
}
