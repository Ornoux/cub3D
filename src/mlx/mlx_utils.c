/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:59:32 by npatron           #+#    #+#             */
/*   Updated: 2024/03/18 15:53:14 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_exit(t_data *data)
{
	(void)data;
	exit(0);
}

void	refresh_map(t_data *data)
{
	if (data->tmp_x != (int)data->p.pos_x)
	{
		data->map[data->tmp_x][data->tmp_y] = '0';
		data->tmp_x = data->p.pos_x;
		data->map[data->tmp_x][data->tmp_y] = 'P';
	}
	if (data->tmp_y != (int)data->p.pos_y)
	{
		data->map[data->tmp_x][data->tmp_y] = '0';
		data->tmp_y = data->p.pos_y;
		data->map[data->tmp_x][data->tmp_y] = 'P';
	}	
}

int	key_press(int key, t_data *data)
{
	refresh_map(data);
	if (key == 119) // W
	{
		if (data->map[(int)floor(data->p.pos_x + data->p.dirp_x * MOVEMENT)][(int)floor(data->p.pos_y)] != '1')
			data->p.pos_x = data->p.pos_x + data->p.dirp_x * MOVEMENT;
		if (data->map[(int)floor(data->p.pos_x)][(int)floor(data->p.pos_y + data->p.dirp_y * MOVEMENT)] != '1')
			data->p.pos_y += data->p.dirp_y * MOVEMENT;
	}
	if (key == 115) // S
	{
		if (data->map[(int)floor(data->p.pos_x - data->p.dirp_x * MOVEMENT)][(int)floor(data->p.pos_y)] != '1')
			data->p.pos_x -=  data->p.dirp_x * MOVEMENT;
		if (data->map[(int)floor(data->p.pos_x)][(int)floor(data->p.pos_y - data->p.dirp_y * MOVEMENT)] != '1')
			data->p.pos_y -= data->p.dirp_y * MOVEMENT;
	}
	if (key == 97) // A
	{
		if (data->map[(int)floor(data->p.pos_x)][(int)floor(data->p.pos_y - data->p.plane_y * MOVEMENT)] != '1')
			data->p.pos_y -=  data->p.plane_y * MOVEMENT;
		if (data->map[(int)floor(data->p.pos_x - data->p.plane_x * MOVEMENT)][(int)floor(data->p.pos_y)] != '1')
			data->p.pos_x -=  data->p.plane_x * MOVEMENT;
	}	
	if (key == 100) // A
	{
		if (data->map[(int)floor(data->p.pos_x)][(int)floor(data->p.pos_y + data->p.plane_y * MOVEMENT)] != '1')
			data->p.pos_y +=  data->p.plane_y * MOVEMENT;
		if (data->map[(int)floor(data->p.pos_x + data->p.plane_x * MOVEMENT)][(int)floor(data->p.pos_y)] != '1')
			data->p.pos_x +=  data->p.plane_x * MOVEMENT;
	}	
	if (key == 65363) // FL DROITE
	{
		data->p.oldDir = data->p.dirp_x;
		data->p.dirp_x = data->p.dirp_x * cos(-ROTATION) - data->p.dirp_y * sin(-ROTATION);
		data->p.dirp_y = data->p.oldDir * sin(-ROTATION) + data->p.dirp_y * cos(-ROTATION);
		data->p.oldPlane = data->p.plane_x;
		data->p.plane_x = data->p.plane_x * cos(-ROTATION) - data->p.plane_y * sin(-ROTATION);
		data->p.plane_y = data->p.oldPlane * sin(-ROTATION) + data->p.plane_y * cos(-ROTATION);
	}
	if (key == 65361) // FL GAUCHE
	{
		data->p.oldDir = data->p.dirp_x;
		data->p.dirp_x = data->p.dirp_x * cos(ROTATION) - data->p.dirp_y * sin(ROTATION);
		data->p.dirp_y = data->p.oldDir * sin(ROTATION) + data->p.dirp_y * cos(ROTATION);
		data->p.oldPlane = data->p.plane_x;
		data->p.plane_x = data->p.plane_x * cos(ROTATION) - data->p.plane_y * sin(ROTATION);
		data->p.plane_y = data->p.oldPlane * sin(ROTATION) + data->p.plane_y * cos(ROTATION);
	}
	return (0);
}


int	key_release(int key, t_data *data)
{
	(void)data;
	if (key == 65307)
		ft_exit(data);
	if (key == 119)
		data->key[0] = 0;
	if (key == 100)
		data->key[1] = 0;
	if (key == 115)
		data->key[2] = 0;
	if (key == 97)
		data->key[3] = 0;
	return (0);
}

int	run_data(t_data *data)
{
	raycasting(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img, 0, 0);
	return (0);
}
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->img->addr + (y * data->img->size_line + x * (data->img->bpp / 8));
	*(unsigned int*)dst = color;
}
