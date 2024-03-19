/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:19:30 by npatron           #+#    #+#             */
/*   Updated: 2024/03/19 19:17:13 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = (void *)malloc(size * nmemb);
	if (!tab)
		return (NULL);
	while (i < nmemb * size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf(" %d | %s\n", i, tab[i]);
		i++;
	}
}

int	jump_line(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->colors)
	{
		while (data->colors[i])
		{
			free(data->colors[i]);
			i++;
		}
	}
	i = 0;
	if (data->textures)
	{
		while (data->textures[i])
		{
			free(data->textures[i]);
			i++;
		}
	}
}
