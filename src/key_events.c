/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:11:44 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/01/21 21:08:34 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_received(int key, t_game *game)
{
	game->key_result = key;
	if (game->key_result == 119 || game->key_result == 97
		|| game->key_result == 115 || game->key_result == 100
		|| game->key_result == 65307)
	{
		if (game->key_result == 65307)
			close_display(game);
		else if (game->key_result == 119)
			move_player_up(game);
		else if (game->key_result == 115)
			move_player_down(game);
		else if (game->key_result == 97)
		{
			game->boolean_player = 1;
			move_player_left(game);
		}
		else if (game->key_result == 100)
		{
			game->boolean_player = 0;
			move_player_right(game);
		}
		printf("steps: %d\n", game->count_moves);
	}
	return (0);
}
