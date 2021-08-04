/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:53:19 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/04 16:08:43 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	sprite_loop(t_data *data)
// {
// 	static int n = 0;

// 	if (n >= 6000)
// 		n = 0;
// 	if (n % 60 < 30)
// 	{
// 		data->images.player = mlx_xpm_file_to_image(data->images.mlx, "./images/dao_front1.xpm", &(data->images.width), &(data->images.height));
// 		mlx_put_image_to_window(data->images.mlx, data->images.win, data->images.player, 0, 0);
// 	}
// 	if (n % 60 >= 30)
// 	{
// 		data->images.player = mlx_xpm_file_to_image(data->images.mlx, "./images/dao_front2.xpm", &(data->images.width), &(data->images.height));
// 		mlx_put_image_to_window(data->images.mlx, data->images.win, data->images.player, 0, 0);
// 	}
// 	n++;
// 	// draw_contents(&(data->so_map), &(data->map_member), &(data->images));
// 	// draw_contents(&(data->so_map), &(data->map_member), &(data->images));
// 	return (0);
// }