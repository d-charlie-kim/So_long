/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:36:06 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/04 15:31:59 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_images(t_images *images, t_map_member *map_member)
{
	images->mlx = mlx_init();
	images->wall1 = mlx_xpm_file_to_image(images->mlx, \
	"./srcs/images/wall1.xpm", &(images->width), &(images->height));
	images->wall2 = mlx_xpm_file_to_image(images->mlx, \
	"./srcs/images/wall2.xpm", &(images->width), &(images->height));
	images->road = mlx_xpm_file_to_image(images->mlx, \
	"./srcs/images/road.xpm", &(images->width), &(images->height));
	images->player = mlx_xpm_file_to_image(images->mlx, \
	"./srcs/images/dao_front1.xpm", &images->width, &images->height);
	images->collectable1 = mlx_xpm_file_to_image(images->mlx, \
	"./srcs/images/collect_ballon.xpm", &(images->width), &(images->height));
	images->collectable2 = mlx_xpm_file_to_image(images->mlx, \
	"./srcs/images/collect_power.xpm", &(images->width), &(images->height));
	images->collectable3 = mlx_xpm_file_to_image(images->mlx, \
	"./srcs/images/collect_speed.xpm", &(images->width), &(images->height));
	images->enemy = mlx_xpm_file_to_image(images->mlx, \
	"./srcs/images/enemy_front1.xpm", &(images->width), &(images->height));
	images->ballon = mlx_xpm_file_to_image(images->mlx, \
	"./srcs/images/ballon1.xpm", &(images->width), &(images->height));
	images->exit = mlx_xpm_file_to_image(images->mlx, \
	"./srcs/images/exit1.xpm", &(images->width), &(images->height));
	images->win = mlx_new_window(images->mlx, \
	map_member->width * images->width, \
	map_member->height * images->height, "DOKKIM_SO_LONG");
}
