/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:03:49 by npatron           #+#    #+#             */
/*   Updated: 2024/03/13 19:36:36 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	dda(t_ray *ray, t_p *p, t_data *data)
{
	while (ray->hit == 0)
	{
		if (ray->side_x <  ray->side_y)
		{
			ray->side_x = ray->side_x + ray->delta_x;
			ray->mapx = ray->mapx + ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y = ray->side_y + ray->delta_y;
			ray->mapy = ray->mapy + ray->step_y;
			ray->side = 1;
		}
		if (data->map[ray->mapx][ray->mapy] == 1)
			ray->hit == 1;
	}
}
void	step(t_ray *ray)
{
	ray->hit = 0;
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (ray->pos_x - ray->mapx) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->mapx + 1.0 - ray->pos_x) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (ray->pos_y - ray->mapy) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->mapy + 1.0 - ray->pos_y) * ray->delta_y;
	}
}

void	values_rays(t_ray *ray, t_p *p, int i)
{
	ray->camera_x = (2 * i) / ((double)WIDTH - 1);
	ray->dir_x = p->dirp_x + (p->plane_x * ray->camera_x);
	ray->dir_y = p->dirp_y + (p->plane_y * ray->camera_x);
	ray->mapx = (int)p->pos_x;
	ray->mapy = (int)p->pos_x;
	ray->delta_x = sqrt(1 + (pow(ray->dir_y, 2) / pow(ray->dir_x, 2)));
	ray->delta_y = sqrt(1 + (pow(ray->dir_x, 2) / pow(ray->dir_y, 2)));
	
}
void	values_wall(t_ray *ray, t_draw *d)
{
	if (ray->side == 0)
		d->perpendicular = (ray->side_x - ray->delta_x);
	else
		d->perpendicular = (ray->side_y - ray->delta_y);
	d->lineheight = (int)(HEIGHT / d->perpendicular);
	d->startdraw = (-(d->lineheight) / 2) + (HEIGHT / 2);
	if (d->startdraw < 0)
		d->startdraw = 0;
	d->end_draw = ((d->lineheight) / 2) + (HEIGHT / 2);
	if (d->end_draw >= HEIGHT)
		d->end_draw = HEIGHT - 1;
}

void	build_column(t_ray *ray, t_draw *d)
{
	int	y;
	


	
	
}


void	raycasting(t_data *data, t_p *p, t_ray *ray, t_draw *d)
{
	int	i;

	i = 0;
	while (i <= WIDTH)
	{
		values_rays(ray, p, i);
		step(ray);
		dda(ray, p, data);
		values_wall(ray, d);
		i++;
	}

}