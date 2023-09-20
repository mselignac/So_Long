/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseligna <mseligna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:53:35 by mseligna          #+#    #+#             */
/*   Updated: 2021/12/22 14:27:10 by mseligna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

# define UP	 119
# define DOWN   115
# define RIGHT  100
# define LEFT   97
# define ESC	65307

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_mlx;

typedef struct s_map
{
	char	**map;
	int		player_i;
	int		player_j;
	int		block_size;
	int		size_x;
	int		size_y;
	int		moves;
}				t_map;

typedef struct s_file
{
	int	fd;
	int	col_max;
	int	line_max;
	int	check_player;
	int	check_exit;
	int	check_collect;
}			t_file;

typedef struct s_struct
{
	t_mlx	mlx_data;
	t_map	map_data;
	t_file	file_data;
	t_mlx	texture[6];
}				t_struct;

char			*ft_itoa(unsigned int nb, int nb_base);
int				get_next_line(int fd, char **line);
void			check_file(char *file, t_struct *all_data);
void			ft_error(int which_error);
int				ft_free(t_struct *all_data, int error);
void			get_map(char *file, t_struct *all_data);
void			check_walls(t_struct *all_data);
void			map_loop(t_struct *all_data);
void			get_textures(t_struct *all_data);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);
unsigned int	mlx_get_pixel(t_struct *all_data, int x, int y, int nb_text);
void			my_mlx_pixel_put(t_struct *all_data, int x, int y, int color);
void			print_block(t_struct *all_data, int pos_x, int pos_y,
					int color);
void			print_img(t_struct *all_data);
void			print_banner(t_struct *all_data);
void			print_move(t_struct *all_data);
int				deal_key(int keycode, t_struct *all_data);
void			player_moves(t_struct *all_data, int move);

#endif