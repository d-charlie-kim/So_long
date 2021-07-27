/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:52:32 by dokkim            #+#    #+#             */
/*   Updated: 2021/07/25 14:37:19 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../get_next_line/get_next_line.h"

void	mapping(char **argv, t_map **so_map, t_map_member *map_member)
{
	int		i;
	int		fd;
	char	*str;
	t_map	*temp;

	str = NULL;
	ft_lst_add(so_map);
	temp = *so_map;
	ft_strcmp(argv[1], ".ber");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("OPEN ERROR");
	while (get_next_line(fd, &str))
	{
		temp->line = str;
		printf("%s\n", temp->line);
		temp->width = ft_strlen(str);
		temp->next = (t_map *)malloc(sizeof(t_map));
		if (!(temp->next))
			ft_error("Malloc Error");
		temp = temp->next;
		temp->next = NULL;
		str = NULL;
	}
	temp->line = str;
	printf("%s\n", temp->line);
	temp->width = ft_strlen(str);
	temp->next = NULL;
	map_validate(so_map, argv, map_member);
}

void	ft_lst_add(t_map **lst)
{
	*lst = (t_map *)malloc(sizeof(t_map));
	if (!(lst))
		ft_error("Malloc Error");
	(*lst)->line = NULL;
	(*lst)->next = NULL;
	(*lst)->width = 0;
}

void	map_validate(t_map **so_map, char **argv, t_map_member *map_member)
{
	put_map_member(map_member, so_map);
	map_is_rectangular(map_member, so_map);
	map_is_valid(map_member);
}