/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:36:18 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/04 15:24:23 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_data *data, int flag)
{
	int	dx;
	int	dy;

	dx = data->map_member.player_x;
	dy = data->map_member.player_y + 1;
	if (flag == 0)
	{
		data->images.player = mlx_xpm_file_to_image(data->images.mlx, \
			"./srcs/images/dao_front1.xpm", &(data->images.width), \
			&(data->images.height));
	}
	else
	{
		data->images.player = mlx_xpm_file_to_image(data->images.mlx, \
			"./srcs/images/dao_front2.xpm", &(data->images.width), \
			&(data->images.height));
	}
	move_player(data, data->map_member.player_x, data->map_member.player_y + 1);
	draw_update(data, dx, dy - 1);
	draw_update(data, dx, dy);
}
