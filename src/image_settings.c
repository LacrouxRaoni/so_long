/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:04:44 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/01/21 21:13:28 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_images(t_game *game)
{
	game->img_height = 50;
	game->img_width = 50;
	game->grass = "./img/grass.xpm";
	game->wall = "./img/wall.xpm";
	game->hero = "./img/hero.xpm";
	game->hero_l = "./img/hero_l.xpm";
	game->collectible = "./img/collectible.xpm";
	game->exit = "./img/exit.xpm";
	game->grass_img = mlx_xpm_file_to_image(game->mlx_ptr, game->grass,
			&game->img_width, &game->img_height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx_ptr, game->wall,
			&game->img_width, &game->img_height);
	game->hero_img = mlx_xpm_file_to_image(game->mlx_ptr, game->hero,
			&game->img_width, &game->img_height);
game->hero_l_img = mlx_xpm_file_to_image(game->mlx_ptr, game->hero_l,
			&game->img_width, &game->img_height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->collectible, &game->img_width, &game->img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx_ptr, game->exit,
			&game->img_width, &game->img_height);
}
