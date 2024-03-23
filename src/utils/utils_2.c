/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:40:13 by npatron           #+#    #+#             */
/*   Updated: 2024/03/20 18:22:02 by npatron          ###   ########.fr       */
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

void	erase_spaces_2(char *replace, char *s, int i, int j)
{
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		replace[j] = s[i];
		i++;
		j++;
	}
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
	erase_spaces_2(replace, s, i, j);
	replace[j] = '\0';
	return (replace);
}

char	*line(int n)
{
	int		i;
	char	*s;

	i = 0;
	s = malloc(sizeof(char) * (n + 3));
	while (i != n + 1)
	{
		s[i] = ' ';
		i++;
	}
	s[i] = '\0';
	return (s);
}
