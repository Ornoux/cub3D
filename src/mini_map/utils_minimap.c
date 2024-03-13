/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:53:19 by npatron           #+#    #+#             */
/*   Updated: 2024/03/13 18:05:54 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	valid_lentab(char **tab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (valid_line(tab[i]) == 1)
			count++;
		i++;
	}
	if (count > 10)
		return (1);
	return (0);
}

int	valid_line(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '0' || s[i] == '1')
			len++;
		i++;
	}
	if (len > 10)
		return (1);
	return (0);
}