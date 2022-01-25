/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:02:18 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/01/25 20:22:26 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_break_line(char *tmp)
{
	int	i;

	i = -1;
	while (tmp[++i])
	{
		if (tmp[i] == '\n')
		{
			if (tmp[i + 1] == '\n')
				return (1);
		}
	}
	return (0);
}

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
	if (validate_break_line(tmp) == 1)
		return (NULL);
	skeleton_map = ft_split(tmp, '\n');
	free (tmp);
	close(game.fd);
	return (skeleton_map);
}
