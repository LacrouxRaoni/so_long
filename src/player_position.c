/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:01:02 by rruiz-la          #+#    #+#             */
/*   Updated: 2021/11/22 20:20:40 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_p_in_map(int *i, int *j, t_game *game)
{
	*i = 0;
	while (game->map[*i] != NULL)
	{
		*j = 0;
		while (game->map[*i][*j] != '\0')
		{
			if (game->map[*i][*j] == 'P')
				return ;
			(*j)++;
		}
		(*i)++;
	}
}
