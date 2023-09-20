/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseligna <mseligna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:08:26 by mseligna          #+#    #+#             */
/*   Updated: 2021/12/21 19:10:05 by mseligna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_block(t_struct *all_data, int pos_x, int pos_y, int nb_text)
{
	int				x;
	int				y;
	unsigned int	color;

	y = pos_y;
	while (y < (all_data->map_data.block_size + pos_y))
	{
		x = pos_x;
		while (x < (all_data->map_data.block_size + pos_x))
		{
			color = mlx_get_pixel(all_data, x - pos_x, y - pos_y, nb_text);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				my_mlx_pixel_put(all_data, x, y, color);
			x++;
		}
		y++;
	}
}

void	print_img(t_struct *all_data)
{
	int	i;
	int	j;

	i = -1 ;
	while (all_data->map_data.map[++i])
	{
		j = -1;
		while (all_data->map_data.map[i][++j])
		{
			print_block(all_data, j * all_data->map_data.block_size,
				i * all_data->map_data.block_size, 4);
			if (all_data->map_data.map[i][j] == '1')
				print_block(all_data, j * all_data->map_data.block_size,
					i * all_data->map_data.block_size, 3);
			else if (all_data->map_data.map[i][j] == 'C')
				print_block(all_data, j * all_data->map_data.block_size,
					i * all_data->map_data.block_size, 0);
			else if (all_data->map_data.map[i][j] == 'E')
				print_block(all_data, j * all_data->map_data.block_size,
					i * all_data->map_data.block_size, 1);
		}
	}
}

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
	mlx_put_image_to_window(all_data->mlx_data.mlx, all_data->mlx_data.win,
		all_data->mlx_data.img, 0, 0);
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
	printf("%d\n", all_data->map_data.moves);
	get_textures(all_data);
	mlx_loop_hook(all_data->mlx_data.mlx, map_input, all_data);
	mlx_hook(all_data->mlx_data.win, 33, 1L << 17, ft_free, all_data);
	mlx_hook(all_data->mlx_data.win, 2, 1L << 0, deal_key, all_data);
	mlx_loop(all_data->mlx_data.mlx);
}
