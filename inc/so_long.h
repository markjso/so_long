/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:30:37 by jmarks            #+#    #+#             */
/*   Updated: 2022/10/01 19:16:50 by jmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "get_next_line.h"

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

typedef struct s_map
{
	void	*player;
	void	*space;
	void	*exit;
	void	*wall;
	void	*collectable;
	int		pcount;
	int		ccount;
	int		ecount;
	int		playerx;
	int		playery;
	int		counter;
	int		steps;
	int		end;
	char	**map;
	char	**map_copy;
	int 	copy_ccount;
	int		copy_ecount;
	int		w;
	int		h;
	int		fd;
	void	*mlx;
	void	*win;
	void	*img;
}	t_map;

int		closeprogram(char *str);
int		exitprogram(void);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	place_player(t_map *map, int height, int width);
void	place_collectable(t_map *map);
int		check_map_file(char *str);
void	check_walls(t_map *map);
int		valid_path(t_map *map, int y, int x);
void	valid_count(t_map *map);
int		valid_map(t_map *map);
int		keypress_hook(int keycode, t_map *map);
void	render_map(t_map *map);
void	parse_map(t_map *map);
void	copy_map(char **origin, char** copy);
void	render_background(t_map *map);

#endif
