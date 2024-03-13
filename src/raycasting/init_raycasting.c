/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:17:09 by npatron           #+#    #+#             */
/*   Updated: 2024/03/13 13:36:46 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_angleplayer(t_data *data, t_p *p)
{
	if (data->no == 1)
	{
		p->dirp_x = 0;
		p->dirp_y = 1;
	}
	else if (data->so == 1)
	{
		p->dirp_x = 0;
		p->dirp_y = -1;
	}
	else if (data->ea == 1)
	{
		p->dirp_x = -1;
		p->dirp_y = 0;
	}
	else if (data->we == 1)
	{
		p->dirp_x = 1;
		p->dirp_y = 0;
	}
}


void	init_raycast(t_data *data, t_p *p, t_ray *ray)
{
	init_angleplayer(data, p);
	p->pos_x = data->posi_x + 0.5;
	p->pos_y = data->posi_y + 0.5;
	
}