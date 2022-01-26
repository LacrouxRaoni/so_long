/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:49:40 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/01/26 00:15:03 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_obj(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'E')
				game->count_e++;
			if (game->map[i][j] == 'C')
				game->count_c++;
			if (game->map[i][j] == 'P')
				game->count_p++;
			j++;
		}
		i++;
	}
	if (game->count_e != 1 || game->count_c < 1 || game->count_p != 1)
		return (1);
	return (0);
}

int	check_map_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' &&
					game->map[i][j] != 'P' && game->map[i][j] != 'C' &&
					game->map[i][j] != 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[0][j] != '1' || game->map[game->height -1][j] != '1'
			|| game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_size(t_game *game)
{
	int	i;
	int	size;

	i = 0;
	while (game->map[i] != NULL)
	{
		size = 0;
		size = ft_strlen(game->map[i]);
		if (size == game->width)
			i++;
		else
			return (1);
	}
	return (0);
}

int	map_settings(t_game *game)
{
	int	return_i;
	int	return_j;
	int	return_k;
	int	return_l;

	game->count_e = 0;
	game->count_c = 0;
	game->count_p = 0;
	game->height = 0;
	game->width = ft_strlen(game->map[0]);
	while (game->map[game->height])
		game->height++;
	game->boolean_player = 0;
	return_i = check_map_chars(game);
	return_j = check_map_obj(game);
	return_k = check_map_walls(game);
	return_l = check_map_size(game);
	if (return_i == 0 && return_j == 0 && return_k == 0 && return_l == 0)
	{
		game->count_moves = 0;
		game->points = game->count_c;
		return (0);
	}
	else
		return (1);
}
