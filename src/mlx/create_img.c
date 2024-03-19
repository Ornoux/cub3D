/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:19:58 by npatron           #+#    #+#             */
/*   Updated: 2024/03/19 20:02:35 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	init_my_texturess(t_data *data)
{
	data->n_texture->img = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[0], &data->n_texture->width, &data->n_texture->height);
	if (!data->n_texture->img)
		return (1);
	data->n_texture->addr = mlx_get_data_addr(data->n_texture->img, &data->n_texture->bpp, &data->n_texture->size_line, &data->n_texture->endian);
	data->s_texture->img = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[1], &data->s_texture->width, &data->s_texture->height);
	if (!data->s_texture->img)
		return (1);
	data->s_texture->addr = mlx_get_data_addr(data->s_texture->img, &data->s_texture->bpp, &data->s_texture->size_line, &data->s_texture->endian);
	data->w_texture->img = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[2], &data->w_texture->width, &data->w_texture->height);
	if (!data->w_texture->img)
		return (1);
	data->w_texture->addr = mlx_get_data_addr(data->w_texture->img, &data->w_texture->bpp, &data->w_texture->size_line, &data->w_texture->endian);
	data->e_texture->img = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[3], &data->e_texture->width, &data->e_texture->height);
	if (!data->e_texture->img)
		return (1);
	data->e_texture->addr = mlx_get_data_addr(data->e_texture->img, &data->e_texture->bpp, &data->e_texture->size_line, &data->e_texture->endian);
	return (0);
}