/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:42:18 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/01/25 20:27:15 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_direction(t_game *game, int i, int j)
{
	if (game->boolean_player == 1)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->hero_l_img, j * game->img_width, i * game->img_height);
	}
	if (game->boolean_player == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->hero_img, j * game->img_width, i * game->img_height);
		game->boolean_player = 0;
	}
}

void	arrange_map_pt2(t_game *game, int i)
{
	int		j;

	j = 0;
	while (game->map[i][j] != '\0')
	{
		if (game->map[i][j] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->wall_img, j * game->img_width, i * game->img_height);
		else if (game->map[i][j] == '0')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->grass_img, j * game->img_width, i * game->img_height);
		else if (game->map[i][j] == 'C')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->collectible_img,
				j * game->img_width, i * game->img_height);
		else if (game->map[i][j] == 'P')
			player_direction (game, i, j);
		else if (game->map[i][j] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->exit_img, j * game->img_width, i * game->img_height);
		j++;
	}
}

int	arrange_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		arrange_map_pt2(game, i);
		i++;
	}
	return (0);
}
