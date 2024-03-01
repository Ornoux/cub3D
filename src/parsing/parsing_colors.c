/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:44:41 by npatron           #+#    #+#             */
/*   Updated: 2024/03/01 18:51:48 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_color(t_data *data, char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == 'F' && s[i + 1] == ' ')
	{
		data->sky++;
		return (1);
	}
	if (s[i] == 'C' && s[i + 1] == ' ')
	{
		data->bg++;
		return (1);
	}
	return (0);
}

void	clean_tab(t_data *data)
{
	int	i;

	i = 0;
	while (data->colors[i])
	{
		data->colors[i] = ft_strdup(skip_colors(data->colors[i]));
		i++;
	}
	i = 0;
	while (data->textures[i])
	{
		data->textures[i] = ft_strdup(skip_textures(data->textures[i]));
		i++;
	}
}

int	condition_color(t_data *data)
{
	if (data->bg == 1 && data->sky == 1)
		return (0);
	return (1);
}

int	get_colors(t_data *data, char **argv)
{
	int		i;
	char	*s;
	int		fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	data->colors = malloc(sizeof(char *) * (2 + 1));
	s = get_next_line(fd);
	while (s)
	{
		if (jump_line(s) == 0 && is_color(data, s) == 1)
		{
			data->colors[i] = s;
			i++;
		}
		s = get_next_line(fd);
		if (i == 2)
			break ;
	}
	data->colors[i] = NULL;
	if (condition_color(data) == 1)
		return (1);
	return (0);
}
