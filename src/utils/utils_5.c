/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:16:03 by npatron           #+#    #+#             */
/*   Updated: 2024/03/12 16:10:26 by npatron          ###   ########.fr       */
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
	if (ft_strcmp(s, "color") == 0)
		printf("Error.\nPlease, check the colors\n");
	else if ((ft_strcmp(s, "char") == 0))
		printf("Error\n. Bad character into the file.\n");
	else if ((ft_strcmp(s, "range") == 0))
		printf("Error\n. Bad range into the file.\n");
	else if ((ft_strcmp(s, "map") == 0))
		printf("Error\n. Error into the map.\n");
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

int	char_valid(char c)
{
	if (c != '1' && c != '0' && c != 'S'
		&& c != 'E' && c != 'W' && c != 'N')
		return (1);
	return (0);
}


int	check_player(char **map, int i, int j)
{
	if ((is_player(map[i][j]) && map[i + 1][j] == ' ')
			|| (is_player(map[i][j]) && char_valid(map[i - 1][j]))
			|| (is_player(map[i][j]) && char_valid(map[i][j + 1]))
			|| (is_player(map[i][j]) && char_valid(map[i][j - 1])))
		return (1);
	return (0);
}

