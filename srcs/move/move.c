/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:05:03 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/03 21:48:42 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_move(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		// mlx_destroy_image(data->images.mlx, data->images.img);
		mlx_destroy_window(data->images.mlx, data->images.win);
		printf("END\n");
		exit(0);
	}
	else if (keycode == LEFT)
		move_left(data);
	else if (keycode == RIGHT)
		move_right(data);
	else if (keycode == DOWN)
		move_down(data);
	else if (keycode == UP)
		move_up(data);
	draw_first(&(data->so_map), &(data->map_member), &(data->images));
	return (0);
}
