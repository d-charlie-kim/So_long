/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 06:03:55 by dokkim            #+#    #+#             */
/*   Updated: 2021/07/27 17:35:29 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int main(int argc, char **argv)
{
	t_map			*so_map;
	t_map_member	map_member;
	t_images		images;

	if (argc != 2)
		ft_error("Error : Argument error");
	map_member_init(&map_member);
	images_init(&images);
	mapping(argv, &so_map, &map_member);
	draw(&so_map, &map_member, &images);
	mlx_loop(images.mlx);
	return (0);
}
