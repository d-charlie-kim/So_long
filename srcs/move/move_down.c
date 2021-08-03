/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:36:18 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/03 21:47:23 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_data *data)
{
	static int	flag = 0;
	int			px;
	int			py;
	char		temp;
	
	px = data->map_member.player_x;
	py = data->map_member.player_y;
	if (flag == 0)
	{
		data->images.player = mlx_xpm_file_to_image(data->images.mlx, "./srcs/images/dao_front2.xpm", &(data->images.width), &(data->images.height));
		flag = 1;
	}
	else
	{
		data->images.player = mlx_xpm_file_to_image(data->images.mlx, "./srcs/images/dao_front1.xpm", &(data->images.width), &(data->images.height));
		flag = 0;		
	}
	temp = get_map_contents(data, px, py + 1);
	if (temp == 'E' && data->map_member.collect_count == data->map_member.collectable)
	{
		// mlx_destroy_image(data->images.mlx, data->images.img);
		mlx_destroy_window(data->images.mlx, data->images.win);
		printf("COMPLETE\n");
		exit(0);
	}
	else if (temp == 'C')
	{
		data->map_member.collect_count++;
		data->map_member.walk_count++;
		printf("Number of Steps : %d\n", data->map_member.walk_count);
		change_map(data, px, py + 1);
	}
	else if (temp == '0')
	{
		data->map_member.walk_count++;
		printf("Number of Steps : %d\n", data->map_member.walk_count);
		change_map(data, px, py + 1);
	}

}
