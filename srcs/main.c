/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 06:03:55 by dokkim            #+#    #+#             */
/*   Updated: 2021/08/03 21:22:46 by dokkim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data			data;

	if (argc != 2)
		ft_error("Error : Argument error");
	data_init(&data);
	mapping(argv, &data);
	map_validate(&data);
	draw(&data);
	// mlx_loop_hook(data.images.mlx, &sprite_loop, &data);
	mlx_key_hook(data.images.win, key_move, &data);
	mlx_hook(data.images.win, 17, 0, x_icon, &data);
	mlx_loop(data.images.mlx);
	return (0);
}
