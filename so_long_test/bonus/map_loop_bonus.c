/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loop_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseligna <mseligna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:35:28 by mseligna          #+#    #+#             */
/*   Updated: 2021/12/22 14:41:41 by mseligna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_input(t_struct *all_data)
{
	if (all_data->mlx_data.img != 0)
	{
		mlx_destroy_image(all_data->mlx_data.mlx, all_data->mlx_data.img);
		all_data->mlx_data.img = mlx_new_image(all_data->mlx_data.mlx,
				all_data->map_data.size_x, all_data->map_data.size_y);
		all_data->mlx_data.addr = mlx_get_data_addr(all_data->mlx_data.img,
				&all_data->mlx_data.bits_per_pixel,
				&all_data->mlx_data.line_length, &all_data->mlx_data.endian);
	}
	print_img(all_data);
	print_block(all_data, all_data->map_data.player_j
		* all_data->map_data.block_size, all_data->map_data.player_i
		* all_data->map_data.block_size, 2);
	print_banner(all_data);
	mlx_put_image_to_window(all_data->mlx_data.mlx, all_data->mlx_data.win,
		all_data->mlx_data.img, 0, 0);
	print_move(all_data);
	return (0);
}

void	map_loop(t_struct *all_data)
{
	all_data->mlx_data.win = mlx_new_window(all_data->mlx_data.mlx,
			all_data->map_data.size_x, all_data->map_data.size_y,
			"best_win_ever");
	all_data->mlx_data.img = mlx_new_image(all_data->mlx_data.mlx,
			all_data->map_data.size_x, all_data->map_data.size_y);
	all_data->mlx_data.addr = mlx_get_data_addr(all_data->mlx_data.img,
			&all_data->mlx_data.bits_per_pixel, &all_data->mlx_data.line_length,
			&all_data->mlx_data.endian);
	mlx_put_image_to_window(all_data->mlx_data.mlx, all_data->mlx_data.win,
		all_data->mlx_data.img, 0, 0);
	get_textures(all_data);
	mlx_loop_hook(all_data->mlx_data.mlx, map_input, all_data);
	mlx_hook(all_data->mlx_data.win, 33, 1L << 17, ft_free, all_data);
	mlx_hook(all_data->mlx_data.win, 2, 1L << 0, deal_key, all_data);
	mlx_loop(all_data->mlx_data.mlx);
}
