/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseligna <mseligna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:54:33 by mseligna          #+#    #+#             */
/*   Updated: 2021/12/21 18:36:37 by mseligna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	deal_key(int keycode, t_struct *all_data)
{
	if (keycode == ESC)
		ft_free(all_data, -1);
	if (keycode == UP)
		player_moves(all_data, 1);
	if (keycode == DOWN)
		player_moves(all_data, 2);
	if (keycode == LEFT)
		player_moves(all_data, 3);
	if (keycode == RIGHT)
		player_moves(all_data, 4);
	return (0);
}

static void	pre_check_move(int move, int *i, int *j)
{
	if (move == 1)
		*i = -1;
	else if (move == 2)
		*i = 1;
	else if (move == 3)
		*j = -1;
	else if (move == 4)
		*j = 1;
}

int	check_move(t_struct *all_data, int move)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	pre_check_move(move, &i, &j);
	if (all_data->map_data.map[all_data->map_data.player_i + i]
		[all_data->map_data.player_j + j] == '1')
		return (0);
	else if (all_data->map_data.map[all_data->map_data.player_i + i]
		[all_data->map_data.player_j + j] == 'E')
		return (2);
	else if (all_data->map_data.map[all_data->map_data.player_i + i]
		[all_data->map_data.player_j + j] == 'C')
	{
		all_data->map_data.map[all_data->map_data.player_i + i]
		[all_data->map_data.player_j + j] = '0';
		all_data->file_data.check_collect--;
	}
	return (1);
}

void	player_moves(t_struct *all_data, int move)
{
	int	check;

	check = check_move(all_data, move);
	if (check != 0)
	{
		if (move == 1)
			all_data->map_data.player_i--;
		else if (move == 2)
			all_data->map_data.player_i++;
		else if (move == 3)
			all_data->map_data.player_j--;
		else if (move == 4)
			all_data->map_data.player_j++;
		all_data->map_data.moves++;
	}
	if (check == 2 && all_data->file_data.check_collect == 0)
		ft_free(all_data, -1);
}
