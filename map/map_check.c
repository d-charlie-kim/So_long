/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 10:58:58 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/01 17:51:02 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../get_next_line/get_next_line.h"

void	put_map_member(t_map_member *map_member, t_map **so_map)
{
	int		i;
	t_map	*temp;

	temp = *so_map;
	while (temp != NULL)
	{
		i = 0;
		while ((temp->line)[i])
		{
			if ((temp->line)[i] == 'C')
				map_member->collectable++;
			else if ((temp->line)[i] == 'P')
				map_member->player++;
			else if ((temp->line)[i] == 'E')
				map_member->exit++;
			else if ((temp->line)[i] == '0')
				map_member->zero++;
			else if ((temp->line)[i] != '1')
				ft_error("Error : Map should be consist of [C P E 0 1]");
			i++;
		}
		temp = temp->next;
	}
}

void	map_is_rectangular(t_map_member	*map_member, t_map **so_map)
{
	t_map	*temp;

	temp = *so_map;
	while (temp->next != NULL)
	{
		if (temp->width != temp->next->width)
			ft_error("Error : Map is not rectangular");
		temp = temp->next;
	}
	map_member->width = (*so_map)->width;
	map_is_surrounded(map_member, so_map);
}

void	map_is_surrounded(t_map_member *map_member, t_map **so_map)
{
	int		i;
	int		n;
	t_map	*temp;

	n = 0;
	temp = *so_map;
	while (temp != NULL)
	{
		temp = temp->next;
		map_member->height++;
	}
	temp = *so_map;
	while (temp != NULL)
	{
		if (n == 0 || n == map_member->height - 1)
		{
			i = 0;
			while (i < map_member->width)
			{
				if ((temp->line)[i] != '1')
					ft_error("Error : Map is not surrounded by wall");
				i++;
			}
		}
		else if ((temp->line)[0] != '1' \
		|| (temp->line)[map_member->width - 1] != '1')
			ft_error("Error : Map is not surrounded by wall");
		temp = temp->next;
		n++;
	}
}

void	map_is_valid(t_map_member *map_member)
{
	if (map_member->collectable < 1 \
	|| map_member->player != 1 \
	|| map_member->exit < 1 \
	|| map_member->zero < 1)
		ft_error("Error : Map is not valid");
}

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit (-1);
}