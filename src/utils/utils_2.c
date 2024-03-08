/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:40:13 by npatron           #+#    #+#             */
/*   Updated: 2024/03/06 17:41:22 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	there_is_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

char	*erase_spaces(char *s)
{
	int		i;
	int		j;
	int		len;
	char	*replace;

	i = 0;
	len = 0;
	if (there_is_spaces(s) == 0)
		return (s);
	while (s[i])
	{
		if (s[i] != ' ')
			len++;
		i++;
	}
	replace = malloc(sizeof(char) * (len + 1));
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		replace[j] = s[i];
		i++;
		j++;
	}
	replace[j] = '\0';
	return (replace);
}

