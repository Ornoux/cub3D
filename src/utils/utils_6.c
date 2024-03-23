/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:23:07 by npatron           #+#    #+#             */
/*   Updated: 2024/03/20 18:24:43 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	char_valid(char c)
{
	if (c != '1' && c != '0' && c != 'S'
		&& c != 'E' && c != 'W' && c != 'N')
		return (1);
	return (0);
}

int	check_player(char **map, int i, int j)
{
	if ((is_player(map[i][j]) && map[i + 1][j] == ' ')
			|| (is_player(map[i][j]) && char_valid(map[i - 1][j]))
			|| (is_player(map[i][j]) && char_valid(map[i][j + 1]))
			|| (is_player(map[i][j]) && char_valid(map[i][j - 1])))
		return (1);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}
