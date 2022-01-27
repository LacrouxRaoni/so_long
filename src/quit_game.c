/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:43:06 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/01/25 17:51:55 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free (map[i]);
	free(map);
}

int	close_display(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->hero_img);
	mlx_destroy_image(game->mlx_ptr, game->hero_l_img);
	mlx_destroy_image(game->mlx_ptr, game->collectible_img);
	mlx_destroy_image(game->mlx_ptr, game->wall_img);
	mlx_destroy_image(game->mlx_ptr, game->grass_img);
	mlx_destroy_image(game->mlx_ptr, game->exit_img);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display (game->mlx_ptr);
	free (game->mlx_ptr);
	free_map (game->map);
	exit (0);
}

int	close_game(t_game *game)
{
	free_map (game->map);
	exit (0);
}
