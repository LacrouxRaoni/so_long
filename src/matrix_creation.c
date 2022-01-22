/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:02:18 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/01/21 22:02:48 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fullfil_matrix(char *file_name, t_game game)
{
	char	*line;
	char	*tmp;
	char	*swap;
	char	**skeleton_map;

	game.fd = open(file_name, O_RDONLY);
	if (game.fd < 0)
		return (NULL);
	tmp = ft_strdup("");
	while (1)
	{
		line = get_next_line(game.fd);
		if (!line)
			break ;
		swap = tmp;
		tmp = ft_strjoin(swap, line);
		free (swap);
		free (line);
	}
	skeleton_map = ft_split(tmp, '\n');
	free (tmp);
	close(game.fd);
	return (skeleton_map);
}
