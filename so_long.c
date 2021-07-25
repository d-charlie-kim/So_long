/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 06:03:55 by dokkim            #+#    #+#             */
/*   Updated: 2021/07/19 06:03:58 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int main(int argc, char **argv)
{
	t_map			*so_map;
	t_map_member	map_member;

	if (argc != 2)
		exit(-1);
	map_member_init(&map_member);
	mapping(argv, &so_map, &map_member);
	draw(&so_map, &map_member);
	return (0);
}
