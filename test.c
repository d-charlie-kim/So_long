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

#include "./minilibx_mms_20200219/mlx.h"
#include <mlx.h>
#include <stdio.h>

// void draw(t_map **so_map)
void main(void)
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

	dx = 0;
	dy = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 600, "TEST_MAP");
	img = mlx_xpm_file_to_image(mlx, "./images/road.xpm", &width, &height);
	printf("width : %d ::: height : %d\n", width, height);
	data = (int *)mlx_get_data_addr(img, &bpp, &size_line, &endian);
	printf("!!!!\n");
	printf("bpp : %d ::: size_line : %d\n", bpp, size_line);
	dy = 0;
	while (dy <= 540)
	{
		dx = 0;
		while (dx <= 540)
		{
			mlx_put_image_to_window(mlx, win, img, dx, dy);
			dx += width;
		}
		dy += height;
	}
	dx = 0;
	img = mlx_xpm_file_to_image(mlx, "./images/dao_front1.xpm", &height, &width);
	mlx_put_image_to_window(mlx, win, img, 248, dx);
	img = mlx_xpm_file_to_image(mlx, "./images/dao_front2.xpm", &height, &width);
	mlx_put_image_to_window(mlx, win, img, 248, dx);
	dx += width;
	img = mlx_xpm_file_to_image(mlx, "./images/dao_back1.xpm", &height, &width);
	mlx_put_image_to_window(mlx, win, img, 248, dx);
	img = mlx_xpm_file_to_image(mlx, "./images/dao_back2.xpm", &height, &width);
	mlx_put_image_to_window(mlx, win, img, 248, dx);
	dx += width;
	img = mlx_xpm_file_to_image(mlx, "./images/dao_left1.xpm", &height, &width);
	mlx_put_image_to_window(mlx, win, img, 248, dx);
	img = mlx_xpm_file_to_image(mlx, "./images/dao_left2.xpm", &height, &width);
	mlx_put_image_to_window(mlx, win, img, 248, dx);
	dx += width;
	img = mlx_xpm_file_to_image(mlx, "./images/dao_right1.xpm", &height, &width);
	mlx_put_image_to_window(mlx, win, img, 248, dx);
	img = mlx_xpm_file_to_image(mlx, "./images/dao_right2.xpm", &height, &width);
	mlx_put_image_to_window(mlx, win, img, 248, dx);
	dx += width;
	dx = 0;
	img = mlx_xpm_file_to_image(mlx, "./images/collect_ballon.xpm", &height, &width);
	mlx_put_image_to_window(mlx, win, img, 186, dx);
	dx += width;
	img = mlx_xpm_file_to_image(mlx, "./images/collect_power.xpm", &height, &width);
	mlx_put_image_to_window(mlx, win, img, 186, dx);
	dx += width;
	img = mlx_xpm_file_to_image(mlx, "./images/collect_speed.xpm", &height, &width);
	mlx_put_image_to_window(mlx, win, img, 186, dx);
	dx += width;
	img = mlx_xpm_file_to_image(mlx, "./images/wall1.xpm", &height, &width);
	mlx_put_image_to_window(mlx, win, img, 186, dx);
	img = mlx_xpm_file_to_image(mlx, "./images/wall2.xpm", &height, &width);
	mlx_put_image_to_window(mlx, win, img, 186, dx);
	dx += width;
	img = mlx_xpm_file_to_image(mlx, "./images/exit1.xpm", &height, &width);
	mlx_put_image_to_window(mlx, win, img, 186, dx);
	img = mlx_xpm_file_to_image(mlx, "./images/exit2.xpm", &height, &width);
	mlx_put_image_to_window(mlx, win, img, 186, dx);
	dx += width;
	img = mlx_xpm_file_to_image(mlx, "./images/enemy1.xpm", &height, &width);
	mlx_put_image_to_window(mlx, win, img, 124, 0);
	dx += width;
	img = mlx_xpm_file_to_image(mlx, "./images/enemy2.xpm", &height, &width);
	mlx_put_image_to_window(mlx, win, img, 124, 0);
	dx += width;


	mlx_loop(mlx);
}