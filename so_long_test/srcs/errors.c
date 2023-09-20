/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseligna <mseligna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:16:49 by mseligna          #+#    #+#             */
/*   Updated: 2021/12/21 19:43:13 by mseligna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(int which_error)
{
	if (which_error == 0)
		printf("Error\nwrong number of arguments\n");
	else if (which_error == 1)
		printf("Error\nfile couldn't be opened\n");
	else if (which_error == 2)
		printf("Error\ninvalid size map\n");
	else if (which_error == 3)
	{
		printf("Error\ninvalid map : must have 1 player only");
		printf(", and at least 1 collectible and exit\n");
	}
	else if (which_error == 4)
		printf("Error\nmemory allocation failed\n");
	else if (which_error == 5)
	{
		printf("Error\nwrong character(s) inside map ");
		printf("(must contain only: '0', '1', 'P', 'C', 'E')\n");
	}
	else if (which_error == 6)
		printf("Error\nmap not closed\n");
	else if (which_error == 7)
		printf("Error\ninvalid size map: too wide for screen\n");
	else if (which_error == 8)
		printf("Error\ninvalid texture\n");
	exit(0);
}

void	clean_mlx(t_struct *all_data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (all_data->texture[i].img)
			mlx_destroy_image(all_data->mlx_data.mlx, all_data->texture[i].img);
		i++;
	}
	if (all_data->mlx_data.img)
		mlx_destroy_image(all_data->mlx_data.mlx, all_data->mlx_data.img);
	if (all_data->mlx_data.win)
		mlx_destroy_window(all_data->mlx_data.mlx, all_data->mlx_data.win);
	if (all_data->mlx_data.mlx)
		mlx_destroy_display(all_data->mlx_data.mlx);
	mlx_loop_end(all_data->mlx_data.mlx);
	free(all_data->mlx_data.mlx);
}

int	ft_free(t_struct *all_data, int error)
{
	int	i;

	i = 0;
	while (all_data->map_data.map[i])
	{
		free(all_data->map_data.map[i]);
		i++;
	}
	free(all_data->map_data.map);
	if (all_data->mlx_data.mlx)
		clean_mlx(all_data);
	if (error != -1)
		ft_error(error);
	exit(0);
	return (0);
}
