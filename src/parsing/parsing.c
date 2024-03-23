/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:06:50 by npatron           #+#    #+#             */
/*   Updated: 2024/03/20 18:08:16 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	error_file(t_data *data, char **argv)
{
	if (get_positions_start(data, argv) == 1 || get_textures(data, argv) == 1
		|| get_colors(data, argv) == 1)
		return (print_error("file"));
	data->textures = tab_in_order(data);
	data->colors = color_in_order(data);
	clean_tab(data);
	if (split_colors(data) == 1)
		return (print_error("color"));
	return (0);
}

int	split_colors(t_data *data)
{
	int		i;
	char	**floor;
	char	**sky;

	floor = ft_split(data->colors[0], ',');
	sky = ft_split(data->colors[1], ',');
	if (tab_len(floor) != 3 || tab_len(sky) != 3)
		return (1);
	data->c_floor = malloc(sizeof(int) * 4);
	data->c_sky = malloc(sizeof(int) * 4);
	i = 0;
	while (floor[i] && sky[i])
	{
		data->c_floor[i] = lil_atoi(floor[i]);
		data->c_sky[i] = lil_atoi(sky[i]);
		i++;
	}
	data->c_floor[i] = 0;
	data->c_sky[i] = 0;
	if (check_colors(data->c_floor) == 1 || check_colors(data->c_sky) == 1)
		return (1);
	return (0);
}

int	check_colors(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] > 255 || tab[i] < 0)
			return (1);
		i++;
	}
	return (0);
}

void	len_max_map(t_data *data, char **argv)
{
	int		len;
	int		fd;
	char	*s;
	int		i;

	len = 0;
	fd = open(argv[1], O_RDONLY);
	s = get_next_line(fd);
	i = 0;
	while (i <= data->start)
	{
		s = get_next_line(fd);
		i++;
	}
	if (!s)
		return ;
	while (i != data->end)
	{
		if (len < ft_strlen(s))
			len = ft_strlen(s);
		s = get_next_line(fd);
		i++;
	}
	data->len_max = len;
	data->start_2 = data->start;
}
