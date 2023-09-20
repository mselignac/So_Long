/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseligna <mseligna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:39:28 by mseligna          #+#    #+#             */
/*   Updated: 2021/12/21 18:11:17 by mseligna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_walls_2(t_struct *all_data, int *i, int *j)
{
	while (all_data->map_data.map[*i][*j] == '1')
		(*j)++;
	if ((*j) != all_data->file_data.line_max)
		ft_free(all_data, 6);
}

static void	if_player(t_struct *all_data, int i, int j)
{
	all_data->map_data.player_i = i;
	all_data->map_data.player_j = j;
}

void	check_walls(t_struct *all_data)
{
	int		i;
	int		j;

	i = 0;
	while (all_data->map_data.map[i])
	{
		j = 0;
		if (i == 0 || i == (all_data->file_data.col_max - 1))
			check_walls_2(all_data, &i, &j);
		else
		{
			while (all_data->map_data.map[i][j])
			{
				if (all_data->map_data.map[i][j] == 'P')
					if_player(all_data, i, j);
				if ((j == 0 || j == (all_data->file_data.line_max - 1))
					&& all_data->map_data.map[i][j] != '1')
					ft_free(all_data, 6);
				j++;
			}
		}
		i++;
	}
}
