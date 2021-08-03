/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:10:53 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/03 19:11:09 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	get_map_contents(t_data *data, int dx, int dy)
{
	t_map	*temp;

	temp = data->so_map;
	while (dy > 0)
	{
		temp = temp->next;
		dy--;
	}
	return ((temp->line)[dx]);
}
