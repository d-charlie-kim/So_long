/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:47:19 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/04 17:59:19 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_map(t_data *data, int dx, int dy)
{
	int		px;
	int		py;
	t_map	*map_temp;

	map_temp = data->so_map;
	px = data->map_member.player_x;
	py = data->map_member.player_y;
	while (dy > 0)
	{
		map_temp = map_temp->next;
		dy--;
	}
	(map_temp->line)[dx] = 'P';
	map_temp = data->so_map;
	while (py > 0)
	{
		map_temp = map_temp->next;
		py--;
	}
	(map_temp->line)[px] = '0';
}
