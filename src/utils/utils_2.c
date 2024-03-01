/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:40:13 by npatron           #+#    #+#             */
/*   Updated: 2024/03/01 18:45:35 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*skip_textures(char *s)
{
	int	i;

	i = 2;
	while (s[i] == ' ' && s[i])
	{
		if (s[i] != ' ')
			break ;
		i++;
	}
	return (s + i);
}

char	*skip_colors(char *s)
{
	int	i;

	i = 1;
	while (s[i] == ' ' && s[i])
	{
		if (s[i] != ' ')
			break ;
		i++;
	}
	return (s + i);
}