/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:44:28 by rruiz-la          #+#    #+#             */
/*   Updated: 2021/11/23 20:53:25 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arrange_x(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'x')
			{
				game->map[i][j] = 'P';
			}
			j++;
		}
		i++;
	}
	arrange_map(game);
}

void	move_player_up(t_game *game)
{
	int	i;
	int	j;

	find_p_in_map(&i, &j, game);
	if (game->map[i][j] == 'P')
	{
		if (game->map[i - 1][j] != '1')
		{
			if (game->map[i - 1][j] == 'E' && game->points > 0)
				return ;
			else if (game->map[i - 1][j] == 'E' && game->points == 0)
			{
				game->count_moves++;
				printf ("THANKS FOR PLAY WITH ME!\n");
				close_display(game);
			}
			else if (game->map[i - 1][j] == 'C')
				game->points--;
			game->count_moves++;
			game->map [i - 1][j] = 'P';
			game->map[i][j] = '0';
			arrange_map(game);
		}
	}
}

void	move_player_down(t_game *game)
{
	int	i;
	int	j;

	find_p_in_map(&i, &j, game);
	if (game->map[i][j] == 'P')
	{
		if (game->map[i + 1][j] != '1')
		{
			if (game->map[i + 1][j] == 'E' && game->points > 0)
				return ;
			else if (game->map[i + 1][j] == 'E' && game->points == 0)
			{
				game->count_moves++;
				printf ("THANKS FOR PLAY WITH ME!\n");
				close_display(game);
			}
			else if (game->map[i + 1][j] == 'C')
				game->points--;
			game->count_moves++;
			game->map [i + 1][j] = 'x';
			game->map[i][j] = '0';
		}
	}
	arrange_x(game);
}

void	move_player_left(t_game *game)
{
	int	i;
	int	j;

	find_p_in_map(&i, &j, game);
	if (game->map[i][j] == 'P')
	{
		if (game->map[i][j - 1] != '1')
		{
			if (game->map[i][j - 1] == 'E' && game->points > 0)
				return ;
			else if (game->map[i][j - 1] == 'E' && game->points == 0)
			{	
				game->count_moves++;
				printf ("THANKS FOR PLAY WITH ME!\n");
				close_display(game);
			}
			else if (game->map[i][j - 1] == 'C')
				game->points--;
			game->count_moves++;
			game->map [i][j - 1] = 'P';
			game->map[i][j] = '0';
			arrange_map(game);
		}
	}
}

void	move_player_right(t_game *game)
{
	int	i;
	int	j;

	find_p_in_map(&i, &j, game);
	if (game->map[i][j] == 'P')
	{
		if (game->map[i][j + 1] != '1')
		{
			if (game->map[i][j + 1] == 'E' && game->points > 0)
				return ;
			else if (game->map[i][j + 1] == 'E' && game->points == 0)
			{	
				game->count_moves++;
				printf ("THANKS FOR PLAY WITH ME!\n");
				close_display(game);
			}
			else if (game->map[i][j + 1] == 'C')
				game->points--;
			game->count_moves++;
			game->map [i][j + 1] = 'x';
			game->map[i][j] = '0';
		}
	}
	arrange_x(game);
}
