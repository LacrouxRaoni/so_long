/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:51:27 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/01/25 21:11:49 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	setbuf(stdout, NULL);
	game.title = "SO_LONG";
	if (file_extension_validation(argv[1]))
		printf ("Error\nNo map specified.\n");
	else if (argc == 2)
	{
		game.map = fullfil_matrix(argv[1], game);
		if (game.map == NULL)
		{
			printf ("Error\nInvalid map.\n");
			exit (1);
		}
		if (map_settings(&game) == 0)
			manage_display(&game);
		else
		{
			printf ("Error\nInvalid map.\n");
			close_game(&game);
			exit (1);
		}
	}
	return (0);
}
