/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:20:35 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/01/26 02:11:50 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	manage_display(t_game *game)
{
	game->mlx_ptr = mlx_init();
	create_images(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->width * game->img_width,
			game->height * game->img_height, game->title);
	arrange_map(game);
	mlx_key_hook(game->win_ptr, key_received, game);
	mlx_hook(game->win_ptr, 17, 0, close_display, game);
	mlx_loop_hook (game->mlx_ptr, arrange_map, game);
	mlx_loop(game->mlx_ptr);
}
