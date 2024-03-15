/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:17:09 by npatron           #+#    #+#             */
/*   Updated: 2024/03/15 14:23:11 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_angleplayer(t_data *data) // OK
{
	if (data->pl == 'N')
	{
		data->p.dirp_x = -1;
		data->p.dirp_y = 0;
	}
	else if (data->pl == 'S')
	{
		data->p.dirp_x = 1;
		data->p.dirp_y = 0;
	}
	else if (data->pl == 'E')
	{
		data->p.dirp_x = 0;
		data->p.dirp_y = -1;
	}
	else if (data->pl == 'W')
	{
		data->p.dirp_x = 0;
		data->p.dirp_y = 1;
	}
}


void	init_raycast(t_data *data) // OK
{
	init_angleplayer(data);
	data->p.pos_x = data->posi_x + 0.5;
	data->p.pos_y = data->posi_y + 0.5;
	data->p.plane_x = 0;
	data->p.plane_y = 0.66;
}