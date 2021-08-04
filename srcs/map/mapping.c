/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:52:32 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/04 08:52:21 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	mapping(char **argv, t_data *data)
{
	int		fd;
	char	*str;

	str = NULL;
	ft_strcmp(argv[1], ".ber");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("OPEN ERROR");
	ft_lst_add(&(data->so_map));
	get_map(fd, &(data->so_map));
	put_map_member(&(data->map_member), &(data->so_map));
}

void	get_map(int fd, t_map **so_map)
{
	int		line_size;
	char	*str;
	t_map	*temp;

	str = NULL;
	temp = *so_map;
	line_size = 1;
	while (line_size != 0)
	{
		line_size = get_next_line(fd, &str);
		if (line_size == -1)
			ft_error("GNL_ERROR");
		temp->line = str;
		temp->width = ft_strlen(str);
		if (line_size != 0)
		{
			ft_lst_add(&(temp->next));
			temp = temp->next;
		}
		str = NULL;
	}
}

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
		map_member->height++;
	}
}
