/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:02:07 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/04 16:07:19 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_data *data, int dx, int dy)
{
	char	temp;

	temp = get_map_contents(data, dx, dy);
	if (temp == 'E' \
	&& data->map_member.collect_count == data->map_member.collectable)
	{
		mlx_destroy_window(data->images.mlx, data->images.win);
		printf("COMPLETE\n");
		exit(0);
	}
	else if (temp == 'C')
	{
		data->map_member.collect_count++;
		data->map_member.walk_count++;
		printf("Number of Steps : %d\n", data->map_member.walk_count);
		change_map(data, dx, dy);
	}
	else if (temp == '0')
	{
		data->map_member.walk_count++;
		printf("Number of Steps : %d\n", data->map_member.walk_count);
		change_map(data, dx, dy);
	}
}
