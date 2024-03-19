/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:03:49 by npatron           #+#    #+#             */
/*   Updated: 2024/03/19 20:05:21 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void dda(t_data *data) //OK
{
	while (data->ray.hit == 0)
	{
		if (data->ray.side_x <  data->ray.side_y)
		{
			data->ray.side_x += data->ray.delta_x;
			data->ray.mapx += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_y += data->ray.delta_y;
			data->ray.mapy += data->ray.step_y;
			data->ray.side = 1;
		}
		if (data->map[data->ray.mapx][data->ray.mapy] == '1')
			data->ray.hit = 1;
		}
}

void	init_step(t_data *data) //OK
{
	if (data->ray.dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_x = (data->p.pos_x - data->ray.mapx) * data->ray.delta_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_x = (data->ray.mapx + 1.0 - data->p.pos_x) * data->ray.delta_x;
	}
	if (data->ray.dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_y = (data->p.pos_y - data->ray.mapy) * data->ray.delta_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_y = (data->ray.mapy + 1.0 - data->p.pos_y) * data->ray.delta_y;
	}
}

void	init_values_rays(t_data *data, int i)
{
	ft_bzero(&data->ray, sizeof(t_ray));
	data->ray.camera_x = (2 * i) / (double)WIDTH - 1;
	data->ray.mapx = (int)data->p.pos_x;
	data->ray.mapy = (int)data->p.pos_y;
	data->ray.dir_x = data->p.dirp_x + (data->p.plane_x * data->ray.camera_x);
	data->ray.dir_y = data->p.dirp_y + (data->p.plane_y * data->ray.camera_x);
	if (data->ray.dir_x == 0)
		data->ray.delta_x = 1e30;
	else
		data->ray.delta_x = fabs(1 / data->ray.dir_x);
	if (data->ray.dir_y == 0)
		data->ray.delta_y = 1e30;
	else
		data->ray.delta_y = fabs(1 / data->ray.dir_y);
}
void	values_wall(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.perpendicular = (data->ray.side_x - data->ray.delta_x);
	else
		data->ray.perpendicular = (data->ray.side_y - data->ray.delta_y);
	if (data->ray.side)
		data->ray.wall_x = data->p.pos_x + data->ray.perpendicular * data->ray.dir_x;
	else
		data->ray.wall_x = data->p.pos_y + data->ray.perpendicular * data->ray.dir_y;
	data->ray.wall_x -= floor(data->ray.wall_x);
	data->ray.lineheight = (HEIGHT / data->ray.perpendicular);
	data->ray.start_draw = (-(data->ray.lineheight) / 2) + (HEIGHT / 2);
	data->ray.end_draw = ((data->ray.lineheight) / 2) + (HEIGHT / 2);
}

char	define_wallcolor(t_data *data)
{
	if (data->ray.dir_x <= 0 && data->ray.dir_y >= 0
		&& data->ray.side == 0)
		return ('N');
	else if (data->ray.dir_x <= 0 && data->ray.dir_y <= 0
			&& data->ray.side == 0)
		return ('N');	
	else if (data->ray.dir_x >= 0 && data->ray.dir_y >= 0
			&& data->ray.side == 0)
		return ('S');
	else if (data->ray.dir_x >= 0 && data->ray.dir_y <= 0
			&& data->ray.side == 0)
		return ('S');
	else if (data->ray.dir_x <= 0 && data->ray.dir_y >= 0
			&& data->ray.side == 1)
		return ('E');
	else if (data->ray.dir_x >= 0 && data->ray.dir_y >= 0
			&& data->ray.side == 1)
		return ('E');
	return ('W');
}

int	choose_color(t_image *img, int x, int y)
{
	// if (define_wallcolor(data) == 'N')
	// 	return (create_trgb(0, 255, 0, 0));
	// else if (define_wallcolor(data) == 'S')
	// 	return (create_trgb(0, 120, 30, 0));
	// else if (define_wallcolor(data) == 'E')
	// 	return (create_trgb(0, 238, 130, 0));
	// else if (define_wallcolor(data) == 'W')
	// 	return (create_trgb(0, 238, 255, 238));
	// return (0);

	char	*pixel;
	int		color;

	pixel = img->addr + (y * img->size_line + x * (img->bpp / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

void	set_floor(t_data *data, int x)
{
	int	y;

	y = data->ray.end_draw;
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(data, x, y, create_trgb(0, data->c_floor[0], data->c_floor[1], data->c_floor[2]));
		y++;
	}
}

void	set_sky(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->ray.start_draw)
	{
		my_mlx_pixel_put(data, x, y, create_trgb(0, data->c_sky[0], data->c_sky[1], data->c_sky[2]));
		y++;
	}
}

t_image	*get_wall(t_data *data)
{
	if (data->ray.side && data->ray.step_y < 0)
		return (data->n_texture);
	if (data->ray.side && data->ray.step_y > 0)
		return (data->s_texture);
	if (!data->ray.side && data->ray.step_x < 0)
		return (data->w_texture);
	if (!data->ray.side && data->ray.step_x > 0)
		return (data->e_texture);
	return (data->n_texture);
}

void	build_column(t_data	*data, int x)
{
	int	y;
	double	y_texture;
	double	step;
	t_image	*texture;

	texture = get_wall(data);
	set_floor(data, x);
	y_texture = 0;
	step = (double)((double)texture->height / (double)(data->ray.end_draw - data->ray.start_draw));
	if (data->ray.start_draw < 0)
	{
		y_texture = step * data->ray.start_draw * -1;
		data->ray.start_draw = 0;
	}
	y = data->ray.start_draw;
	while (y <= data->ray.end_draw)
	{
		if (y >= HEIGHT)
			break ;
		my_mlx_pixel_put(data, x, y, choose_color(texture, data->ray.wall_x * texture->width, y_texture));
		y++;
		y_texture += step;
	}
	set_sky(data, x);
}


int	raycasting(t_data *data)
{
	int	i;
	
	i = 0;
	while (i <= WIDTH)
	{
		init_values_rays(data, i);
		init_step(data);
		dda(data);
		values_wall(data);
		build_column(data, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img, 0, 0);
	return (0);
}