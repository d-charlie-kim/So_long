/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_contents.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:27:47 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/03 21:12:16 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_map_member *map_member, t_images *images, int dx, int dy)
{
	map_member->player_x = dx / images->width;
	map_member->player_y = dy / images->height;
	mlx_put_image_to_window(images->mlx, images->win, images->player, dx, dy);
}

void	draw_collectable(t_map_member *map_member, t_images *images, \
															int dx, int dy)
{
	if (((dx / images->width) % 3) == 0)
		mlx_put_image_to_window(images->mlx, images->win, \
		images->collectable1, dx, dy);
	if (((dx / images->width) % 3) == 1)
		mlx_put_image_to_window(images->mlx, images->win, \
		images->collectable2, dx, dy);
	if (((dx / images->width) % 3) == 2)
		mlx_put_image_to_window(images->mlx, images->win, \
		images->collectable3, dx, dy);
}

void	draw_exit(t_map_member *map_member, t_images *images, int dx, int dy)
{
	mlx_put_image_to_window(images->mlx, images->win, images->exit, dx, dy);
}

void	draw_wall(t_map_member *map_member, t_images *images, int dx, int dy)
{
	if (((dx / images->width) % 2) == 0)
		mlx_put_image_to_window(images->mlx, images->win, \
		images->wall1, dx, dy);
	if (((dx / images->width) % 2) == 1)
		mlx_put_image_to_window(images->mlx, images->win, \
		images->wall2, dx, dy);
}

// void	draw_enemy(t_map_member *map_member, t_images *images, int dx, int dy)
// {
// 	map_member->enemy_x = dx / images->width;
// 	map_member->enemy_y = dy / images->height;
// 	mlx_put_image_to_window(images->mlx, images->win, images->enemy, dx, dy);	
// }