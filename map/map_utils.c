/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 10:47:10 by dokkim            #+#    #+#             */
/*   Updated: 2021/07/29 16:29:06 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../get_next_line/get_next_line.h"

void	ft_strcmp(char *str, char *str2)
{
	int i;
	int	j;

	i = 0;
	j = 3;
	while (str[i])
		i++;
	i--;
	while (j >= 0)
	{
		if (str[i] != str2[j])
			ft_error("Error : Map file is not valid");
		i--;
		j--;
	}
}

void	ft_putstr(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	map_member_init(t_map_member *map_member)
{
	map_member->width = 0;
	map_member->height = 0;
	map_member->zero = 0;
	map_member->collectable = 0;
	map_member->player = 0;
	map_member->exit = 0;
	map_member->walk_count = 0;
	map_member->collect_count = 0;
	map_member->player_x = 0;
	map_member->player_y = 0;
}

void	images_init(t_images *images)
{
	images->mlx = NULL;
	images->win = NULL;
	images->wall = NULL;
	images->road = NULL;
	images->player = NULL;
	images->collectable1 = NULL;
	images->collectable2 = NULL;
	images->collectable3 = NULL;
	images->enemy = NULL;
	images->exit = NULL;
}