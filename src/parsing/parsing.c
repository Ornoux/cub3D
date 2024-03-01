/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:06:50 by npatron           #+#    #+#             */
/*   Updated: 2024/02/29 19:47:13 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int error_file(t_data *data, char **argv)
{
	if (get_textures(data, argv) == 1 || get_colors(data, argv) == 1)
	{
		printf("Error.\nPlease, check the file.\n");
		return (1);
	}
	return (0);
}