/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:42:39 by npatron           #+#    #+#             */
/*   Updated: 2024/03/20 14:48:14 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	moves_forward_backward_left(t_data *data, int key)
{
	if (key == 119)
	{
		if (data->map[(int)floor(data->p.pos_x + data->p.dirp_x * MOVEMENT)] \
			[(int)floor(data->p.pos_y)] != '1')
			data->p.pos_x = data->p.pos_x + data->p.dirp_x * MOVEMENT;
		if (data->map[(int)floor(data->p.pos_x)] \
			[(int)floor(data->p.pos_y + data->p.dirp_y * MOVEMENT)] != '1')
			data->p.pos_y += data->p.dirp_y * MOVEMENT;
	}
	if (key == 115)
	{
		if (data->map[(int)floor(data->p.pos_x - data->p.dirp_x * MOVEMENT)] \
			[(int)floor(data->p.pos_y)] != '1')
			data->p.pos_x -= data->p.dirp_x * MOVEMENT;
		if (data->map[(int)floor(data->p.pos_x)] \
			[(int)floor(data->p.pos_y - data->p.dirp_y * MOVEMENT)] != '1')
			data->p.pos_y -= data->p.dirp_y * MOVEMENT;
	}
}

void	moves_sides(t_data *data, int key)
{
	if (key == 97)
	{
		if (data->map[(int)floor(data->p.pos_x)] \
		[(int)floor(data->p.pos_y - data->p.plane_y * MOVEMENT)] != '1')
			data->p.pos_y -= data->p.plane_y * MOVEMENT;
		if (data->map[(int)floor(data->p.pos_x - data->p.plane_x * MOVEMENT)] \
		[(int)floor(data->p.pos_y)] != '1')
			data->p.pos_x -= data->p.plane_x * MOVEMENT;
	}
	if (key == 100)
	{
		if (data->map[(int)floor(data->p.pos_x)] \
		[(int)floor(data->p.pos_y + data->p.plane_y * MOVEMENT)] != '1')
			data->p.pos_y += data->p.plane_y * MOVEMENT;
		if (data->map[(int)floor(data->p.pos_x + data->p.plane_x * MOVEMENT)] \
		[(int)floor(data->p.pos_y)] != '1')
			data->p.pos_x += data->p.plane_x * MOVEMENT;
	}
}
