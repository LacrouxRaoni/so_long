/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_extension.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz-la <rruiz-la@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 00:11:51 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/01/26 00:12:52 by rruiz-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_extension_validation(char *file)
{
	char	*ext;

	if (!file)
		return (1);
	ext = ft_strrchr(file, '.');
	if (!ext)
		return (1);
	if (ft_strncmp(ext, ".ber", 5) == 0)
		return (0);
	return (1);
}
