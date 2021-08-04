/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 10:47:10 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/04 18:29:25 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_strcmp(char *str, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 3;
	while (str[i])
		i++;
	i--;
	while (j >= 0)
	{
		if (str[i] != str2[j])
			ft_error("Error\n : Map file is not valid");
		i--;
		j--;
	}
}

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit (-1);
}

void	ft_lst_add(t_map **lst)
{
	*lst = (t_map *)malloc(sizeof(t_map));
	if (!(lst))
		ft_error("Error\n : Malloc Error");
	(*lst)->line = NULL;
	(*lst)->next = NULL;
	(*lst)->width = 0;
}
