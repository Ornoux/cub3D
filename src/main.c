/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:20:44 by npatron           #+#    #+#             */
/*   Updated: 2024/03/07 17:05:02 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	init_data(t_data *data)
{
	data->textures = NULL;
	data->colors = NULL;
	data->map = NULL;
	data->len_max = 0;
	data->ea = 0;
	data->so = 0;
	data->no = 0;
	data->we = 0;
	data->bg = 0;
	data->sky = 0;
	data->start = 0;
	data->end = 0;
	data->len_max = 0;
	data->tall_map = 0;
	data->pos_x = 0;
	data->pos_y = 0;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	(void)data;
	if (good_arg(argc, argv) == 1)
		exit(EXIT_FAILURE);
	init_data(data);
	if (error_file(data, argv) == 1)
		return (0);
	len_max_map(data, argv);
	get_map(data, argv);
	if (is_valid_map(data))
	{
		printf("Error.\nError into the map.\n");
		return (0);
	}
	free_data(data);
	free(data);
	return (0);
}
