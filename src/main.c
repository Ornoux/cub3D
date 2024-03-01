/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:20:44 by npatron           #+#    #+#             */
/*   Updated: 2024/03/01 18:54:59 by npatron          ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	(void)data;
	if (good_arg(argc, argv) == 1)
		exit(EXIT_FAILURE);
	init_data(data);
	if (error_file(data, argv) == 1)
		return (0);
	print_tab(data->textures);
	print_tab(data->colors);
	free_data(data);
	free(data);
	return (0);
}
