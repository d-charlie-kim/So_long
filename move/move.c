/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:47:19 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/01 17:42:34 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	x_icon(int keycode, t_data *data)
{
	printf("END\n");
	exit(0);
	return (0);
}

int	move(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		// mlx_destroy_image(data->images.mlx, data->images.img);
		mlx_destroy_window(data->images.mlx, data->images.win);
		printf("END\n");
		exit(0);
	}
	else if (keycode == LEFT)
		move_left(data);
	else if (keycode == RIGHT)
		move_right(data);
	else if (keycode == DOWN)
		move_down(data);
	else if (keycode == UP)
		move_up(data);
	draw_contents(&(data->so_map), &(data->map_member), &(data->images));
	return (0);
}

void	move_left(t_data *data)
{
	static int	flag = 0;
	int			px;
	int			py;
	char		temp;

	px = data->map_member.player_x;
	py = data->map_member.player_y;
	if (flag == 0)
	{
		data->images.player = mlx_xpm_file_to_image(data->images.mlx, \
		"./images/dao_left1.xpm", &(data->images.width), &(data->images.height));
		flag = 1;
	}
	else
	{
		data->images.player = mlx_xpm_file_to_image(data->images.mlx,\
		"./images/dao_left2.xpm", &(data->images.width), &(data->images.height));
		flag = 0;		
	}
	temp = get_map_contents(data, px - 1, py);
	if (temp == 'E' \
	&& data->map_member.collect_count == data->map_member.collectable)
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
		change_map(data, px - 1, py);
	}
	else if (temp == '0')
	{
		data->map_member.walk_count++;
		printf("Number of Steps : %d\n", data->map_member.walk_count);
		change_map(data, px - 1, py);
	}
}

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

void	move_right(t_data *data)
{
	static int	flag = 0;
	int			px;
	int			py;
	char		temp;
	
	px = data->map_member.player_x;
	py = data->map_member.player_y;
	if (flag == 0)
	{
		data->images.player = mlx_xpm_file_to_image(data->images.mlx, "./images/dao_right1.xpm", &(data->images.width), &(data->images.height));
		flag = 1;
	}
	else
	{
		data->images.player = mlx_xpm_file_to_image(data->images.mlx, "./images/dao_right2.xpm", &(data->images.width), &(data->images.height));
		flag = 0;		
	}
	temp = get_map_contents(data, px + 1, py);
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
		change_map(data, px + 1, py);
	}
	else if (temp == '0')
	{
		data->map_member.walk_count++;
		printf("Number of Steps : %d\n", data->map_member.walk_count);
		change_map(data, px + 1, py);
	}

	
}

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
		data->images.player = mlx_xpm_file_to_image(data->images.mlx, "./images/dao_front2.xpm", &(data->images.width), &(data->images.height));
		flag = 1;
	}
	else
	{
		data->images.player = mlx_xpm_file_to_image(data->images.mlx, "./images/dao_front1.xpm", &(data->images.width), &(data->images.height));
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

void	move_up(t_data *data)
{
	static int flag = 0;
	int			px;
	int			py;
	char		temp;

	px = data->map_member.player_x;
	py = data->map_member.player_y;
	if (flag == 0)
	{
		data->images.player = mlx_xpm_file_to_image(data->images.mlx, "./images/dao_back1.xpm", &(data->images.width), &(data->images.height));
		flag = 1;
	}
	else
	{
		data->images.player = mlx_xpm_file_to_image(data->images.mlx, "./images/dao_back2.xpm", &(data->images.width), &(data->images.height));
		flag = 0;		
	}
	temp = get_map_contents(data, px, py - 1);
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
		change_map(data, px, py - 1);
	}
	else if (temp == '0')
	{
		data->map_member.walk_count++;
		printf("Number of Steps : %d\n", data->map_member.walk_count);
		change_map(data, px, py - 1);
	}

}