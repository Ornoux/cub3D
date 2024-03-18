/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:19:58 by npatron           #+#    #+#             */
/*   Updated: 2024/03/18 16:31:22 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	init_my_texturess(t_data *data)
{
	data->n_texture->img = mlx_xpm_to_image(data->mlx_ptr, &data->textures[0], 0, 0);
	data->s_texture->img = mlx_xpm_to_image(data->mlx_ptr, &data->textures[1], 0, 0);
	data->w_texture->img = mlx_xpm_to_image(data->mlx_ptr, &data->textures[2], 0, 0);
	data->e_texture->img = mlx_xpm_to_image(data->mlx_ptr, &data->textures[3], 0, 0);
	
	if (data->n_texture->img == NULL || data->s_texture->img == NULL \
		|| data->w_texture->img == NULL || data->e_texture->img == NULL)
		return (1);
	return (0);
}