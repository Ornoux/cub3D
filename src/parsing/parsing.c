/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:06:50 by npatron           #+#    #+#             */
/*   Updated: 2024/03/06 18:42:52 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	error_file(t_data *data, char **argv)
{
	if (get_positions_start(data, argv) == 1 || get_textures(data, argv) == 1
		|| get_colors(data, argv) == 1)
	{
		printf("Error.\nPlease, check the file.\n");
		return (1);
	}
	data->textures = tab_in_order(data);
	data->colors = color_in_order(data);
	clean_tab(data);
	if (split_colors(data) == 1)
	{
		printf("Error.\nPlease, check the file.\n");
		return (1);
	}
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

