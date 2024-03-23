/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:01:32 by npatron           #+#    #+#             */
/*   Updated: 2024/03/20 18:12:57 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_texture2(t_data *data, char *s, int i)
{
	if (s[i] == 'W' && s[i + 1] == 'E' && s[i + 2] == ' ')
	{
		data->we++;
		return (1);
	}
	else if (s[i] == 'E' && s[i + 1] == 'A' && s[i + 2] == ' ')
	{
		data->ea++;
		return (1);
	}
	else
		return (0);
}

int	is_texture(t_data *data, char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == 'N' && s[i + 1] == 'O' && s[i + 2] == ' ')
	{
		data->no++;
		return (1);
	}
	else if (s[i] == 'S' && s[i + 1] == 'O' && s[i + 2] == ' ')
	{
		data->so++;
		return (1);
	}
	else
		return (is_texture2(data, s, i));
}

int	condition_texture(t_data *data)
{
	if (data->ea == 1 && data->no == 1
		&& data->we == 1 && data->so == 1)
		return (0);
	return (1);
}

int	fill_textures_tab(char **tab, t_data *data, int i, char *s)
{
	if (jump_line(s) == 0 && is_texture(data, s) == 1)
	{
		tab[i] = s;
		return (1);
	}
	return (0);
}

int	get_textures(t_data *data, char **argv)
{
	int		i;
	int		count;
	char	*s;
	int		fd;

	i = 0;
	count = 0;
	fd = open(argv[1], O_RDONLY);
	data->textures = malloc(sizeof(char *) * (4 + 1));
	s = get_next_line(fd);
	while (s)
	{
		i += fill_textures_tab(data->textures, data, i, s);
		s = get_next_line(fd);
		count++;
	}
	data->textures[i] = NULL;
	if (condition_texture(data) == 1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
