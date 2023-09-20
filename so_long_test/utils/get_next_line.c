/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseligna <mseligna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:02:54 by mseligna          #+#    #+#             */
/*   Updated: 2021/12/21 18:11:55 by mseligna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*ft_strjoin(char *line, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	if (line == NULL)
	{
		tmp = malloc(2 * sizeof(char));
		tmp[0] = c;
		tmp[1] = '\0';
	}
	else
	{
		while (line[i])
			i++;
		tmp = malloc(i + 2 * sizeof(char));
		i = -1;
		while (line[++i])
			tmp[i] = line[i];
		tmp[i] = c;
		tmp[i + 1] = '\0';
		free(line);
		line = NULL;
	}
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	char	c;
	char	*tmp;

	c = 0;
	tmp = NULL;
	if (read(fd, &c, 0) < 0 || fd < 0 || !line)
		return (-1);
	if (tmp == NULL)
		tmp = ft_strjoin(tmp, '\0');
	while (read(fd, &c, 1) && c != '\n')
		tmp = ft_strjoin(tmp, c);
	*line = tmp;
	return (c == '\n');
}
