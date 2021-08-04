/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:36:20 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/04 15:24:05 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_data *data, int flag)
{
	int	dx;
	int	dy;

	dx = data->map_member.player_x + 1;
	dy = data->map_member.player_y;
	if (flag == 0)
	{
		data->images.player = mlx_xpm_file_to_image(data->images.mlx, \
			"./srcs/images/dao_right1.xpm", &(data->images.width), \
			&(data->images.height));
	}
	else
	{
		data->images.player = mlx_xpm_file_to_image(data->images.mlx, \
			"./srcs/images/dao_right2.xpm", &(data->images.width), \
			&(data->images.height));
	}
	move_player(data, data->map_member.player_x + 1, data->map_member.player_y);
	draw_update(data, dx - 1, dy);
	draw_update(data, dx, dy);
}
