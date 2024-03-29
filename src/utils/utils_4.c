/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:08:32 by npatron           #+#    #+#             */
/*   Updated: 2024/03/20 18:22:23 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	erase_greg_de_mavie(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '\n')
				tab[i][j] = '\0';
			j++;
		}
		i++;
	}
}

int	file_in_order(char *s)
{
	if (jump_line(s) == 0 && is_color_2(s) == 0 && is_texture_3(s) == 0)
		return (1);
	return (0);
}

char	**tab_in_order(t_data *data)
{
	int		i;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * 5);
	while (data->textures[i])
	{
		if (is_texture_3(data->textures[i]) == 1)
			tab[0] = ft_strdup(data->textures[i]);
		else if (is_texture_3(data->textures[i]) == 2)
			tab[1] = ft_strdup(data->textures[i]);
		else if (is_texture_3(data->textures[i]) == 3)
			tab[2] = ft_strdup(data->textures[i]);
		else if (is_texture_3(data->textures[i]) == 4)
			tab[3] = ft_strdup(data->textures[i]);
		i++;
	}
	tab[4] = NULL;
	erase_greg_de_mavie(tab);
	return (tab);
}

char	**color_in_order(t_data *data)
{
	int		i;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * 3);
	while (data->colors[i])
	{
		if (is_color_2(data->colors[i]) == 1)
			tab[0] = ft_strdup(data->colors[i]);
		else if (is_color_2(data->colors[i]) == 2)
			tab[1] = ft_strdup(data->colors[i]);
		i++;
	}
	tab[2] = NULL;
	return (tab);
}

char	*copy_string(char *s, int n)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc(sizeof(char) * (n + 2) + 1);
	i = 1;
	j = 0;
	dest[0] = ' ';
	while (s[i])
	{
		dest[i] = s[j];
		i++;
		j++;
	}
	while (i <= (n + 1))
	{
		dest[i] = ' ';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
