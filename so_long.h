/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:55:11 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/01/25 11:06:05 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_so_long
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*title;
	int		height;
	int		width;
	int		img_height;
	int		img_width;
	int		count_p;
	int		count_c;
	int		count_e;
	int		count_moves;
	int		points;
	int		fd;
	int		key_result;
	int		boolean_player;
	void	*grass_img;
	void	*wall_img;
	void	*hero_img;
	void	*hero_l_img;
	void	*collectible_img;
	void	*exit_img;
	char	*grass;
	char	*wall;
	char	*hero;
	char	*hero_l;
	char	*collectible;	
	char	*exit;	
	char	**map;
}	t_game;

int		map_settings(t_game *game);
int		file_extension_validation(char *file);
/**
	*to check character numbers in map
**/
int		check_map_obj(t_game *game);
/**
	*to check if map have the chars requesteded
**/
int		check_map_chars(t_game *game);
/**
	*to check if map area is filled with '1'
**/
int		check_map_walls(t_game *game);
int		key_received(int key, t_game *game);
void	move_player_up(t_game *game);
void	move_player_down(t_game *game);
void	move_player_left(t_game *game);
void	move_player_right(t_game *game);
void	player_direction(t_game *game, int i, int j);
void	manage_display(t_game *game);
void	arrange_x(t_game *game);
void	arrange_map(t_game *game);
void	arrange_map_pt2(t_game *game, int i);
void	find_p_in_map(int *i, int *j, t_game *game);
char	**fullfil_matrix(char *file_name, t_game game);
void	create_images(t_game *game);
int		close_game(t_game *game);
int		close_display(t_game *game);
void	free_map(char **map);
#endif
