/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:19:58 by npatron           #+#    #+#             */
/*   Updated: 2024/03/14 15:33:06 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	create_img(t_data *data)
{
	void	*ptr_img;
	char	*buf;
	int		bit;
	int		line;
	int		endian;
	int		color;
	int		pixel;
	int		x;
	int		y;
	
	color = create_trgb(0, data->c_sky[0], data->c_sky[1], data->c_sky[2]);
	ptr_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	buf = mlx_get_data_addr(ptr_img, &bit, &line, &endian);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y > HEIGHT / 2)
				color = create_trgb(0, data->c_floor[0], data->c_floor[1], data->c_floor[2]);
			pixel = (y * line) + (x * 4);
			buf[pixel] = color;
			buf[pixel + 1] = color >> 8;
			buf[pixel + 2] = color >> 16;
			buf[pixel + 3] = color >> 24;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, ptr_img, 0, 0);
}

void	create_img2(t_data *data)
{
	void	*ptr_img;
	char	*buf;
	int		bit;
	int		line;
	int		endian;
	int		color;
	int		pixel;
	int		x;
	int		y;
	
	color = 0x0FF0000;
	ptr_img = mlx_new_image(data->mlx_ptr, 200, 200);
	buf = mlx_get_data_addr(ptr_img, &bit, &line, &endian);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel = (y * line) + (x * 4);
			buf[pixel] = color;
			buf[pixel + 1] = color >> 8;
			buf[pixel + 2] = color >> 16;
			buf[pixel + 3] = color >> 24;
			x++;
		}
		y++;
	}
	//mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, ptr_img, 0, 0);
}