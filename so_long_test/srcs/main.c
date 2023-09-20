/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseligna <mseligna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:18:50 by mseligna          #+#    #+#             */
/*   Updated: 2021/12/21 18:45:12 by mseligna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_struct(t_struct *all_data)
{
	all_data->mlx_data.mlx = NULL;
	all_data->mlx_data.win = NULL;
	all_data->mlx_data.img = NULL;
	all_data->mlx_data.addr = NULL;
	all_data->mlx_data.bits_per_pixel = 0;
	all_data->mlx_data.line_length = 0;
	all_data->mlx_data.endian = 0;
	all_data->file_data.fd = 0;
	all_data->file_data.col_max = 0;
	all_data->file_data.line_max = 0;
	all_data->file_data.check_collect = 0;
	all_data->file_data.check_exit = 0;
	all_data->file_data.check_player = 0;
	all_data->map_data.map = NULL;
	all_data->map_data.block_size = 48;
	all_data->map_data.size_x = 0;
	all_data->map_data.size_y = 0;
	all_data->map_data.moves = 0;
	all_data->texture[0].img = NULL;
	all_data->texture[1].img = NULL;
	all_data->texture[2].img = NULL;
	all_data->texture[3].img = NULL;
	all_data->texture[4].img = NULL;
	all_data->texture[5].img = NULL;
}

static void	check_screen_size(t_struct *all_data)
{
	int		screen_x;
	int		screen_y;

	screen_x = 0;
	screen_y = 0;
	all_data->mlx_data.mlx = mlx_init();
	mlx_get_screen_size(all_data->mlx_data.mlx, &screen_x, &screen_y);
	if (all_data->map_data.size_x > screen_x
		|| all_data->map_data.size_y > screen_y)
		ft_free(all_data, 7);
}

int	main(int argc, char **argv)
{
	t_struct	all_data;
	int			i;

	init_struct(&all_data);
	i = 0;
	if (argc != 2)
		ft_error(0);
	while (argv[1][i] != '.')
		i++;
	if (argv[1][i + 1] == 'b' && argv[1][i + 2] == 'e' && argv[1][i + 3] == 'r'
		&& argv[1][i + 4] == '\0' )
		check_file(argv[1], &all_data);
	else
	{
		printf("Error\nWrong file, please use <file.ber>\n");
		return (0);
	}
	all_data.map_data.size_x = all_data.file_data.line_max
		* all_data.map_data.block_size;
	all_data.map_data.size_y = all_data.file_data.col_max
		* all_data.map_data.block_size;
	check_screen_size(&all_data);
	map_loop(&all_data);
	return (0);
}
