/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:16:03 by npatron           #+#    #+#             */
/*   Updated: 2024/03/20 18:23:43 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_good_char(t_data *data, char c, int x, int y)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		data->player++;
		data->posi_x = x;
		data->posi_y = y;
		data->pl = c;
	}
	if (c == ' ' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == '1'
		|| c == '0')
		return (0);
	return (1);
}

int	error_into_file(t_data *data, char **argv)
{
	int		fd;
	int		i;
	char	*s;

	fd = open(argv[1], O_RDONLY);
	i = 1;
	s = get_next_line(fd);
	while (i < data->start_2)
	{
		if (is_texture_3(s) == 0 && is_color_2(s) == 0
			&& jump_line(s) == 0)
			return (1);
		s = get_next_line(fd);
		i++;
	}
	return (0);
}

int	print_error(char *s)
{
	if (ft_strcmp(s, "file") == 0)
		printf("Error.\nPlease, check the file\n");
	else if (ft_strcmp(s, "color") == 0)
		printf("Error.\nPlease, check the colors\n");
	else if ((ft_strcmp(s, "char") == 0))
		printf("Error.\nBad character into the file.\n");
	else if ((ft_strcmp(s, "range") == 0))
		printf("Error.\nBad range into the file.\n");
	else if ((ft_strcmp(s, "map") == 0))
		printf("Error.\nError into the map.\n");
	else if ((ft_strcmp(s, "textures") == 0))
		printf("Error.\nCheck your textures.\n");
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return (0);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W'
		|| c == 'E')
		return (1);
	return (0);
}
