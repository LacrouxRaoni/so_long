/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:20:35 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/01/25 21:29:59 by rruiz-la         ###   ########.fr       */
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
	mlx_hook(game->win_ptr, 9, 1L << 21, arrange_map, game);
	mlx_key_hook(game->win_ptr, key_received, game);
	mlx_hook(game->win_ptr, 17, 0, close_display, game);
	mlx_loop(game->mlx_ptr);
}
