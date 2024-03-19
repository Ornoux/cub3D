/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:20:44 by npatron           #+#    #+#             */
/*   Updated: 2024/03/19 11:38:51 by npatron          ###   ########.fr       */
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
	data->posi_x = 0;
	data->posi_y = 0;
	data->player = 0;
	data->pl = 0;
	data->rota = 0;
}


int	main(int argc, char **argv)
{
	t_data	data;

	if (good_arg(argc, argv) == 1)
		exit(EXIT_FAILURE);
	init_data(&data);
	if (error_file(&data, argv) == 1)
		return (0);
	len_max_map(&data, argv);
	get_map(&data, argv);
	if (is_valid_map(&data) || error_into_file(&data, argv))
	{
		print_error("map");
		return (0);
	}
	data.tmp_x = (int)data.p.pos_x;
	data.tmp_y = (int)data.p.pos_y;
	//ft_bzero(&data.p, sizeof(t_p));
	init_raycast(&data);
	mlx(&data);
	// free_data(&data);
	// free(&data);
	exit(0);
	return (0);
}
