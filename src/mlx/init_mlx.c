/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:20:35 by npatron           #+#    #+#             */
/*   Updated: 2024/03/13 16:49:07 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	put_img(t_data *data, void	*img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, x, y);
}

void	*ft_img(t_data *data, char *name)
{
	int		a;
	void	*new;

	new = mlx_xpm_file_to_image(data->mlx_ptr, name, &a, &a);
	if (!new) {
		exit(0);}
	return (new);
}

void	init_mlx(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, \
	HEIGHT, "cub3D");
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, ft_img(data, "./src/img/mini_player.xpm"), WIDTH - 10, HEIGHT - 10);
	create_img(data);
	create_img2(data);
	mlx_loop_hook(data->mlx_ptr, run_data, data);
	mlx_hook(data->mlx_win, 33, 1L << 17, ft_exit, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, key_release, data);
	mlx_loop(data->mlx_ptr);
}

void	init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->key = ft_calloc(6, sizeof(int));
	data->mini_floor = ft_img(data, "./src/img/floor_minimap.xpm");
	data->mini_wall = ft_img(data, "./src/img/wall_minimap.xpm");
	data->mini_player = ft_img(data, "./src/img/mini_player.xpm");
}

void	mlx(t_data *data)
{
	init(data);
	init_mlx(data);
}
