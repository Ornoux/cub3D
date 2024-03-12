/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:59:32 by npatron           #+#    #+#             */
/*   Updated: 2024/03/11 19:09:43 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_exit(t_data *data)
{
	(void)data;
	exit(0);
}

int	key_press(int key, t_data *data)
{
	if (key == 65307)
		ft_exit(data);
	if (key == 119)
		printf("DEVANT\n");
	if (key == 100)
		printf("DROITE\n");
	if (key == 115)
		printf("BAS\n");
	if (key == 97)
		printf("GAUCHE\n");
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
