/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseligna <mseligna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:41:41 by mseligna          #+#    #+#             */
/*   Updated: 2021/12/21 18:31:39 by mseligna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	get_textures_ter(t_struct *all_data)
{
	all_data->texture[4].addr = mlx_get_data_addr(all_data->texture[4].img,
			&all_data->texture[4].bits_per_pixel,
			&all_data->texture[4].line_length, &all_data->texture[4].endian);
	all_data->texture[5].addr = mlx_get_data_addr(all_data->texture[5].img,
			&all_data->texture[5].bits_per_pixel,
			&all_data->texture[5].line_length, &all_data->texture[5].endian);
}

static void	get_textures_bis(t_struct *all_data)
{
	all_data->texture[4].img = mlx_xpm_file_to_image(all_data->mlx_data.mlx,
			"./textures/rug.xpm", &all_data->texture[4].width,
			&all_data->texture[4].height);
	if (all_data->texture[4].img == NULL)
		ft_free(all_data, 8);
	all_data->texture[5].img = mlx_xpm_file_to_image(all_data->mlx_data.mlx,
			"./textures/banner.xpm", &all_data->texture[5].width,
			&all_data->texture[5].height);
	if (all_data->texture[5].img == NULL)
		ft_free(all_data, 8);
	all_data->texture[0].addr = mlx_get_data_addr(all_data->texture[0].img,
			&all_data->texture[0].bits_per_pixel,
			&all_data->texture[0].line_length, &all_data->texture[0].endian);
	all_data->texture[1].addr = mlx_get_data_addr(all_data->texture[1].img,
			&all_data->texture[1].bits_per_pixel,
			&all_data->texture[1].line_length, &all_data->texture[1].endian);
	all_data->texture[2].addr = mlx_get_data_addr(all_data->texture[2].img,
			&all_data->texture[2].bits_per_pixel,
			&all_data->texture[2].line_length, &all_data->texture[2].endian);
	all_data->texture[3].addr = mlx_get_data_addr(all_data->texture[3].img,
			&all_data->texture[3].bits_per_pixel,
			&all_data->texture[3].line_length, &all_data->texture[3].endian);
	get_textures_ter(all_data);
}

void	get_textures(t_struct *all_data)
{
	all_data->texture[0].img = mlx_xpm_file_to_image(all_data->mlx_data.mlx,
			"./textures/wool_ball.xpm", &all_data->texture[0].width,
			&all_data->texture[0].height);
	if (all_data->texture[0].img == NULL)
		ft_free(all_data, 8);
	all_data->texture[1].img = mlx_xpm_file_to_image(all_data->mlx_data.mlx,
			"./textures/box.xpm", &all_data->texture[1].width,
			&all_data->texture[1].height);
	if (all_data->texture[1].img == NULL)
		ft_free(all_data, 8);
	all_data->texture[2].img = mlx_xpm_file_to_image(all_data->mlx_data.mlx,
			"./textures/cat.xpm", &all_data->texture[2].width,
			&all_data->texture[2].height);
	if (all_data->texture[2].img == NULL)
		ft_free(all_data, 8);
	all_data->texture[3].img = mlx_xpm_file_to_image(all_data->mlx_data.mlx,
			"./textures/plant.xpm", &all_data->texture[3].width,
			&all_data->texture[3].height);
	if (all_data->texture[3].img == NULL)
		ft_free(all_data, 8);
	get_textures_bis(all_data);
}
