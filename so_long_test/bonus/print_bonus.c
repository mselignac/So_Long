/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseligna <mseligna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:18:12 by mseligna          #+#    #+#             */
/*   Updated: 2021/12/22 14:45:30 by mseligna         ###   ########.fr       */
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

void	print_banner(t_struct *all_data)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < 48)
	{
		x = 0;
		while (x < 144)
		{
			color = mlx_get_pixel(all_data, x, y, 5);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				my_mlx_pixel_put(all_data, x, y, color);
			x++;
		}
		y++;
	}
}

void	print_move(t_struct *all_data)
{
	char	*count;

	count = ft_itoa(all_data->map_data.moves, 10);
	if (all_data->map_data.moves == 0)
		mlx_string_put(all_data->mlx_data.mlx, all_data->mlx_data.win, 70, 25,
			0x00000000, "0");
	else
		mlx_string_put(all_data->mlx_data.mlx, all_data->mlx_data.win, 70, 25,
			0x00000000, count);
	free(count);
}
