/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:40:36 by dokkim            #+#    #+#             */
/*   Updated: 2021/07/27 18:06:17 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw(t_map **so_map, t_map_member *map_member, t_images *images)
{
	// int		bpp;
	// int		endian;
	// int		size_line;
	// int		*data;
	int		height;
	int		width;

	printf("map width : %d ::: map height : %d\n", map_member->width, map_member->height);
	// data = (int *)mlx_get_data_addr(images->road, &bpp, &size_line, &endian);
	get_images(images, map_member);
	printf("height : %d ::: width : %d\n", images->height, images->width);
	draw_background(so_map, map_member, images);
	draw_contents(so_map, map_member, images);
}

void	get_images(t_images *images, t_map_member *map_member)
{
	images->mlx = mlx_init();
	// images->win = (images->mlx, map_member->width * images->width, map_member->height * images->height, "DOKKIM_SO_LONG");
	images->wall = mlx_xpm_file_to_image(images->mlx, "./images/wall1.xpm", &images->width, &images->height);
	images->road = mlx_xpm_file_to_image(images->mlx, "./images/road.xpm", &images->width, &images->height);
	images->player = mlx_xpm_file_to_image(images->mlx, "./images/dao_front1.xpm", &images->width, &images->height);
	images->collectable = mlx_xpm_file_to_image(images->mlx, "./images/collect_ballon.xpm", &images->width, &images->height);
	images->enemy = NULL;
	images->exit = mlx_xpm_file_to_image(images->mlx, "./images/exit1.xpm", &images->width, &images->height);
	images->win = mlx_new_window(images->mlx, map_member->width * images->width, map_member->height * images->height, "DOKKIM_SO_LONG");
}

void	draw_contents(t_map **so_map, t_map_member *map_member, t_images *images)
{
	int	i;
	int	dx;
	int	dy;
	t_map	*map_temp;
	
	map_temp = *so_map;
	i = 0;
	dx = 0;
	dy = 0;
	while (map_temp != NULL)
	{
		while (i < map_member->width)
		{
			printf("%c\n", map_temp->line[i]);
			if ((map_temp->line)[i] == 'C')
				mlx_put_image_to_window(images->mlx, images->win, images->collectable, dx, dy);
			else if ((map_temp->line)[i] == 'P')
				mlx_put_image_to_window(images->mlx, images->win, images->player, dx, dy);
			else if ((map_temp->line)[i] == 'E')
				mlx_put_image_to_window(images->mlx, images->win, images->exit, dx, dy);
			else if ((map_temp->line)[i] == '1')
				mlx_put_image_to_window(images->mlx, images->win, images->wall, dx, dy);
			dx = dx + images->width;
			i++;
		}
		dx = 0;
		dy = dy + images->height;
		map_temp = map_temp->next;
		i = 0;
	}
}

void	draw_background(t_map **so_map, t_map_member *map_member, t_images *images)
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