/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseligna <mseligna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:30:53 by mseligna          #+#    #+#             */
/*   Updated: 2021/12/21 18:31:58 by mseligna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}

unsigned int	mlx_get_pixel(t_struct *all_data, int x, int y, int nb_text)
{
	return (*(unsigned int *)(all_data->texture[nb_text].addr
		+ (x * all_data->texture[nb_text].bits_per_pixel / 8 + y
			* all_data->texture[nb_text].line_length)));
}

void	my_mlx_pixel_put(t_struct *all_data, int x, int y, int color)
{
	char	*dst;

	dst = all_data->mlx_data.addr + (y * all_data->mlx_data.line_length
			+ x * (all_data->mlx_data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
