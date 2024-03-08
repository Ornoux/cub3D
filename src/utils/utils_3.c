/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:03:40 by npatron           #+#    #+#             */
/*   Updated: 2024/03/06 18:36:13 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*skip_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] && s[i] >= 'A' && s[i] <= 'Z')
		i++;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	return (s + i);
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	print_int_tab(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%d\n", tab[i]);
		i++;
	}
}


int	is_texture_3(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == 'N' && s[i + 1] == 'O' && s[i + 2] == ' ')
		return (1);
	else if (s[i] == 'S' && s[i + 1] == 'O' && s[i + 2] == ' ')
		return (2);
	else if (s[i] == 'W' && s[i + 1] == 'E' && s[i + 2] == ' ')
		return (3);
	else if (s[i] == 'E' && s[i + 1] == 'A' && s[i + 2] == ' ')
		return (4);
	else
		return (0);
}

int	is_color_2(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == 'F' && s[i + 1] == ' ')
		return (1);
	if (s[i] == 'C' && s[i + 1] == ' ')
		return (2);
	return (0);
}

