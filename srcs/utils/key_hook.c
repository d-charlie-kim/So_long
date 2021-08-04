/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:23:08 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/04 16:07:23 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	x_icon(int keycode, t_data *data)
{
	printf("END\n");
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	static int	flag = 0;

	if (keycode == 53)
	{
		mlx_destroy_window(data->images.mlx, data->images.win);
		printf("END\n");
		exit(0);
	}
	else if (keycode == LEFT)
		move_left(data, flag);
	else if (keycode == RIGHT)
		move_right(data, flag);
	else if (keycode == DOWN)
		move_down(data, flag);
	else if (keycode == UP)
		move_up(data, flag);
	if (flag == 1)
		flag = 0;
	else if (flag == 0)
		flag = 1;
	return (0);
}
