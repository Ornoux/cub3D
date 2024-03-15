/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:59:32 by npatron           #+#    #+#             */
/*   Updated: 2024/03/15 18:22:07 by npatron          ###   ########.fr       */
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
	if (data->tmp_x < (int)data->p.pos_x)
	{
		data->map[data->tmp_x][data->tmp_y] = '0';
	}
	if (data->tmp_y < (int)data->p.pos_y)
	data->map[(int)data->posi_x][(int)data->posi_y] = 'P';
	
}


int	key_press(int key, t_data *data)
{
	if (key == 65307)
		ft_exit(data);
	if (key == 119) // W
	{
		if (data->map[(int)(data->p.pos_x + data->p.dirp_x * MOVEMENT)][(int)data->p.pos_y] != '1')
			data->p.pos_x +=  data->p.dirp_x * MOVEMENT;
	}
	if (key == 115) // S
	{
		if (data->map[(int)(data->p.pos_x - data->p.dirp_x * MOVEMENT)][(int)data->p.pos_y] != '1')
			data->p.pos_x -=  data->p.dirp_x * MOVEMENT;
	}
	if (key == 100) //D
	{
		if (data->map[(int)(data->p.pos_x)][(int)(data->p.pos_y + data->p.dirp_y * MOVEMENT)] != '1')
			data->p.pos_y +=  data->p.plane_y * MOVEMENT;
	}
	if (key == 97) // A
	{
		if (data->map[(int)data->p.pos_y][(int)(data->p.pos_y - data->p.plane_y * MOVEMENT)] != '1')
			data->p.pos_y -=  data->p.plane_y * MOVEMENT;
	}
	if (key == 65363) // FL DROITE
	{
		data->p.oldDir = data->p.dirp_x;
		data->p.dirp_x = data->p.dirp_x * cos(-ROTATION) - data->p.dirp_y * sin(-ROTATION);
		data->p.dirp_y = data->p.oldDir * sin(-MOVEMENT) + data->p.dirp_y * cos(-ROTATION);
		data->p.oldPlane = data->p.plane_x;
		data->p.plane_x = data->p.plane_x * cos(-ROTATION) - data->p.plane_y * sin(-ROTATION);
		data->p.plane_y = data->p.oldPlane * sin(-ROTATION) + data->p.plane_y * cos(-ROTATION);
	}
	if (key == 65361) // FL GAUCHE
	{
		data->p.oldDir = data->p.dirp_x;
		data->p.dirp_x = data->p.dirp_x * cos(ROTATION) - data->p.dirp_y * sin(ROTATION);
		data->p.dirp_y = data->p.oldDir * sin(MOVEMENT) + data->p.dirp_y * cos(ROTATION);
		data->p.oldPlane = data->p.plane_x;
		data->p.plane_x = data->p.plane_x * cos(ROTATION) - data->p.plane_y * sin(ROTATION);
		data->p.plane_y = data->p.oldPlane * sin(ROTATION) + data->p.plane_y * cos(ROTATION);
	}
	printf("POS : X : %f Y : %f\n", data->p.pos_x, data->p.pos_y);
	printf("------------------------------\n");
	printf("PERPENDICULAR %f\n", data->ray.perpendicular);
	printf("------------------------------\n");
	printf("END DRAW %f\n", data->ray.perpendicular);
	printf("CHECK : %c\n", data->map[(int)(data->p.pos_x + data->p.pos_y * MOVEMENT)][(int)data->p.pos_y]);
	printf("PLANE X %f\n", data->p.plane_x);
	printf("PLANE Y %f\n", data->p.plane_y);

	

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
	(void)data;
	raycasting(data);
	/*int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
				put_img(data, data->mini_floor, WEIGHT, HEIGHT);
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
				put_img(data, data->mini_player, WEIGHT, HEIGHT);
			if (data->map[i][j] == '1')
				put_img(data, data->mini_wall, WEIGHT, HEIGHT);
			if (data->map[i][j] == ' ')
				put_img(data, data->mini_wall, WEIGHT, HEIGHT);
			j++;
		}
		i++;
	}*/
	return (0);
}
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
