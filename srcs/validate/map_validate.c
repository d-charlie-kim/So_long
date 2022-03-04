/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:07:18 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/04 18:27:28 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_validate(t_data *data)
{
	map_is_rectangular(&(data->map_member), &(data->so_map));
	map_is_surrounded(&(data->map_member), &(data->so_map));
	map_is_valid(data->map_member);
}

void	map_is_rectangular(t_map_member	*map_member, t_map **so_map)
{
	t_map	*temp;

	temp = *so_map;
	while (temp->next != NULL)
	{
		if (temp->width != temp->next->width)
			ft_error("Error\n : Map is not rectangular");
		temp = temp->next;
	}
	map_member->width = (*so_map)->width;
}

void	map_is_surrounded(t_map_member *map_member, t_map **so_map)
{
	t_map	*temp;

	temp = *so_map;
	first_last_line(temp->line, map_member->width);
	while (temp != NULL && temp->next != NULL)
	{
		if ((temp->line)[0] != '1' \
		|| (temp->line)[map_member->width - 1] != '1')
			ft_error("Error\n : Map is not surrounded by wall");
		temp = temp->next;
	}
	first_last_line(temp->line, map_member->width);
}

void	first_last_line(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] != '1')
			ft_error("Error\n : Map is not surrounded by wall");
		i++;
	}
}

void	map_is_valid(t_map_member map_member)
{
	if (map_member.player != 1 || map_member.exit < 1 \
		|| map_member.collectable < 1)
		ft_error("Error\n : Map is not valid");
}
