/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:02:23 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/04 16:07:32 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_update(t_data *data, int dx, int dy)
{
	t_map	*temp;
	int		n;

	n = dy;
	temp = data->so_map;
	while (n > 0)
	{
		temp = temp->next;
		n--;
	}
	if ((temp->line)[dx] == '0')
	{
		mlx_put_image_to_window(data->images.mlx, data->images.win, \
		data->images.road, dx * data->images.width, dy * data->images.height);
	}
	else if ((temp->line)[dx] == 'P')
	{
		mlx_put_image_to_window(data->images.mlx, data->images.win, \
		data->images.player, dx * data->images.width, dy * data->images.height);
		data->map_member.player_x = dx;
		data->map_member.player_y = dy;
	}
}
