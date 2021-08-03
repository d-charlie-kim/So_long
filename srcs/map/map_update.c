/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:47:19 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/03 19:08:44 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_map(t_data *data, int dx, int dy)
{
	int		sx;
	int		sy;
	char	temp;
	t_map	*map_temp;

	map_temp = data->so_map;
	sx = data->map_member.player_x;
	sy = data->map_member.player_y;
	while (dy > 0)
	{
		map_temp = map_temp->next;
		dy--;
	}
	(map_temp->line)[dx] = 'P';
	map_temp = data->so_map;
	while (sy > 0)
	{
		map_temp = map_temp->next;
		sy--;
	}
	(map_temp->line)[sx] = '0';
}
