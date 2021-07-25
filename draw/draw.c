/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:40:36 by dokkim            #+#    #+#             */
/*   Updated: 2021/07/19 20:40:38 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void draw(t_map **so_map, t_map_member *map_member)
{
	void	*mlx;
	void	*win;
	void	*img;

	int		bpp;
	int		endian;
	int		size_line;

	int		*data;

	int		dx;
	int		dy;

	int		height;
	int		width;

	t_map			*map_temp;
	t_map_member	*member_temp;
	map_temp = *so_map;
	member_temp = map_member;

	dx = 0;
    dy = 0;
	mlx = mlx_init();
	printf("%d ::: %d\n", member_temp->width, member_temp->height);
	win = mlx_new_window(mlx, member_temp->width * 62, member_temp->height * 73, "DOKKIM_SO_LONG");
	img = mlx_xpm_file_to_image(mlx, "./images/road.xpm", &width, &height);
	printf("height : %d ::: width : %d\n", height, width);
	data = (int *)mlx_get_data_addr(img, &bpp, &size_line, &endian);
	printf("bpp : %d ::: size_line : %d\n", bpp, size_line);

	// draw road fuction(&mlx, &win, &img, so_map, struct);
	dx = 0;
	while (dx <= (map_member->width - 1) * width)
	{
		dy = 0;
		while (dy <= (map_member->height - 1) * height)
		{
	        mlx_put_image_to_window(mlx, win, img, dx, dy);
	    	dy += height;
		}
		dx += width;
	}

	//draw others function(&mlx, &win, &img, so_map, struct);
	int	i;

	i = 0;
	dx = 0;
	dy = 0;
	while (map_temp != NULL)
	{
		while (i < map_member->width)
		{
			printf("%c\n", map_temp->line[i]);
			if ((map_temp->line)[i] == 'C')
			{
				if (i % 3 == 1)
					img = mlx_xpm_file_to_image(mlx, "./images/collect_ballon.xpm", &width, &height);
				else if (i % 3 == 2)
					img = mlx_xpm_file_to_image(mlx, "./images/collect_speed.xpm", &width, &height);
				else if (i % 3 == 0)
					img = mlx_xpm_file_to_image(mlx, "./images/collect_power.xpm", &width, &height);
				mlx_put_image_to_window(mlx, win, img, dx, dy);
			}
			else if ((map_temp->line)[i] == 'P')
			{
				img = mlx_xpm_file_to_image(mlx, "./images/dao_front1.xpm", &width, &height);
				mlx_put_image_to_window(mlx, win, img, dx, dy);
			}
			else if ((map_temp->line)[i] == 'E')
			{
				img = mlx_xpm_file_to_image(mlx, "./images/exit1.xpm", &width, &height);
				mlx_put_image_to_window(mlx, win, img, dx, dy);
			}
			else if ((map_temp->line)[i] == '1')
			{
				if (i % 2 == 1)
					img = mlx_xpm_file_to_image(mlx, "./images/wall2.xpm", &width, &height);
				else if (i % 1 == 0)
					img = mlx_xpm_file_to_image(mlx, "./images/wall1.xpm", &width, &height);
				mlx_put_image_to_window(mlx, win, img, dx, dy);
			}
			dx = dx + width;
			i++;
		}
		dx = 0;
		dy += height;
		map_temp = map_temp->next;
		i = 0;
	}
	mlx_loop(mlx);
}