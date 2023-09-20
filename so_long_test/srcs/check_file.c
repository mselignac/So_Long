/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseligna <mseligna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:38:33 by mseligna          #+#    #+#             */
/*   Updated: 2021/12/22 14:42:00 by mseligna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	get_map_2(t_struct *all_data)
{
	int		i;
	int		j;
	char	*line;
	int		ret;

	ret = 1;
	i = 0;
	while (ret > 0)
	{
		j = -1;
		all_data->map_data.map[i] = malloc((all_data->file_data.line_max + 1)
				* sizeof(char));
		if (!(all_data->map_data.map[i]))
			ft_free(all_data, 4);
		ret = get_next_line(all_data->file_data.fd, &line);
		while (line[++j])
			all_data->map_data.map[i][j] = line[j];
		all_data->map_data.map[i][j] = '\0';
		free(line);
		i++;
	}
	return (i);
}

void	get_map(char *file, t_struct *all_data)
{
	int	i;

	all_data->file_data.fd = open(file, O_RDONLY);
	if (all_data->file_data.fd == -1)
		ft_error(1);
	all_data->map_data.map = malloc((all_data->file_data.col_max + 1)
			* sizeof(char*));
	if (!(all_data->map_data.map))
		ft_free(all_data, 4);
	i = get_map_2(all_data);
	all_data->map_data.map[i] = '\0';
	close(all_data->file_data.fd);
	check_walls(all_data);
}

static void	if_not_rectangular(t_struct *all_data, int i, char *line)
{
	if (i != all_data->file_data.line_max)
	{
		free(line);
		ft_error(2);
	}
}

static void	check_file_2(t_struct *all_data, int *ret)
{
	int		i;
	char	*line;

	i = 0;
	*ret = get_next_line(all_data->file_data.fd, &line);
	while (line[i])
	{
		if (line[i] == 'P')
			all_data->file_data.check_player++;
		else if (line[i] == 'C')
			all_data->file_data.check_collect++;
		else if (line[i] == 'E')
			all_data->file_data.check_exit++;
		else if (line[i] != '0' && line[i] != '1')
		{
			free(line);
			ft_error(5);
		}
		i++;
	}
	if (!all_data->file_data.line_max)
		all_data->file_data.line_max = i;
	if_not_rectangular(all_data, i, line);
	all_data->file_data.col_max++;
	free(line);
}

void	check_file(char *file, t_struct *all_data)
{
	int	ret;

	all_data->file_data.fd = open(file, O_RDONLY);
	if (all_data->file_data.fd == -1)
		ft_error(1);
	ret = 1;
	while (ret > 0)
		check_file_2(all_data, &ret);
	close(all_data->file_data.fd);
	if (all_data->file_data.check_player == 0
		|| all_data->file_data.check_player > 1
		|| all_data->file_data.check_collect == 0
		|| all_data->file_data.check_exit == 0)
		ft_error(3);
	get_map(file, all_data);
}
