/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_first.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:40:36 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/03 21:40:40 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_data *data)
{
	// int		bpp;
	// int		endian;
	// int		size_line;
	// int		*data;

	// data = (int *)mlx_get_data_addr(images->road, &bpp, &size_line, &endian);
	get_images(&(data->images), &(data->map_member));
	draw_background(&(data->map_member), &(data->images));
	draw_first(&(data->so_map), &(data->map_member), &(data->images));
}

void	draw_first(t_map **so_map, t_map_member *map_member, t_images *images)
{
	int	dy;
	t_map	*map_temp;
	
	map_temp = *so_map;
	dy = 0;
	while (map_temp != NULL)
	{
		draw_contents(map_member, images, dy, map_temp->line);
		dy = dy + images->height;
		map_temp = map_temp->next;
	}
}

void	draw_contents(t_map_member *map_member, t_images *images, int dy, char *line)
{
	int	i;
	int	dx;

	i = 0;
	dx = 0;
	while (i < map_member->width)
	{
		if (line[i] == 'C')
			draw_collectable(map_member, images, dx, dy);
		else if (line[i] == 'P')
			draw_player(map_member, images, dx, dy);
		else if (line[i] == 'E')
			draw_exit(map_member, images, dx, dy);
		else if (line[i] == '1')
			draw_wall(map_member, images, dx, dy);
		i++;
		dx = dx + images->width;
	}	
}

void	draw_background(t_map_member *map_member, t_images *images)
{
	int	dx;
	int	dy;
	
	dx = 0;
	while (dx <= (map_member->width - 1) * images->width)
	{
		dy = 0;
		while (dy <= (map_member->height - 1) * images->height)
		{
	        mlx_put_image_to_window(images->mlx, images->win, images->road, dx, dy);
	    	dy = dy + images->height;
		}
		dx = dx + images->width;
	}
}