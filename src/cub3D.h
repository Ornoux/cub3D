/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:27:59 by npatron           #+#    #+#             */
/*   Updated: 2024/03/22 19:10:46 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"

# define WIDTH 1920
# define HEIGHT 1080
# define MOVEMENT 0.2
# define ROTATION 0.0000002
# define PI 3.1415926

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}			t_image;

typedef struct s_ray
{
	// Direction des rayons
	double	dir_x;
	double	dir_y;

	// DeltaX et DeltaY
	double	delta_x;
	double	delta_y;

	// Carre de la map
	int		mapx;
	int		mapy;

	// Longeur entre le prochain step
	double	side_x;
	double	side_y;

	// Step pour le DDA sur les bordures
	double	step_x;
	double	step_y;

	// 1 || 0 pour savoir durant le DDA si un mur est touche par le ray
	int		hit;

	// Side : NS || EW mur hit
	int		side;
	double	color_side;
	double	camera_x;

	//corrected dist
	double	perpendicular;
	double	lineheight;

	int		start_draw;
	int		end_draw;

	double	wall_x;

}				t_ray;

typedef struct s_p
{
	// Positions du joueur
	double	pos_x;
	double	pos_y;

	// Direction du player
	double	dirp_x;
	double	dirp_y;

	// Cam/Rota
	double	plane_x;
	double	plane_y;

	double	old_dir;
	double	old_plane;
}				t_p;

typedef struct s_data
{
	char	pl;
	int		*key;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		sky;
	int		bg;
	int		start;
	int		start_2;
	int		end;
	char	**map;
	char	**textures;
	char	**colors;
	int		len_max;
	int		tall_map;
	int		*c_floor;
	int		*c_sky;
	int		player;
	int		posi_x;
	int		posi_y;
	int		tmp_x;
	int		tmp_y;
	double	rota;
	void	*mlx_ptr;
	void	*mlx_win;
	t_image	*img;
	t_image	*n;
	t_image	*s;
	t_image	*e;
	t_image	*w;
	t_ray	ray;
	t_p		p;
}			t_data;

// UTILS PART
void	print_tab(char **tab);
char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(char *src);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(const char *s);
int		jump_line(char *str);
void	free_data(t_data *data);
char	*skip_spaces(char *s);
char	*erase_spaces(char *s);
char	**ft_split(char const *s, char c);
int		tab_len(char **tab);
int		lil_atoi(char *s);
void	print_int_tab(int *tab);
char	*copy_string(char *s, int n);
void	get_map(t_data *data, char **argv);
char	*line(int n);
int		is_good_char(t_data *data, char c, int i, int j);
int		error_into_file(t_data *data, char **argv);
int		check_player(char **map, int i, int j);
void	init_raycast(t_data *data);
int		is_player(char c);
// MLX PART
int		ft_exit(t_data *data);
int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);
int		run_data(t_data *datad);
int		mlx(t_data *data);
void	put_img(t_data *data, void	*img, int x, int y);
int		create_trgb(int t, int r, int g, int b);
int		raycasting(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		init_my_texturess(t_data *data);
void	mini_map(t_data *data);
void	moves_forward_backward_left(t_data *data, int key);
void	moves_sides(t_data *data, int key);
void	build_column_2(t_data *data, int x);
void	set_floor(t_data *data, int x);
int		choose_color(t_image *img, int x, int y);
void	len_max_map(t_data *data, char **argv);
int		raycasting(t_data *data);
char	*line(int n);
// PARSING PART
int		good_arg(int argc, char **argv);
int		get_textures(t_data *data, char **argv);
int		get_colors(t_data *data, char **argv);
int		condition_texture(t_data *data);
int		condition_color(t_data *data);
int		error_file(t_data *data, char **argv);
void	clean_tab(t_data *data);
int		is_texture(t_data *data, char *s);
int		check_colors(int *tab);
int		split_colors(t_data *data);
int		is_color(t_data *data, char *s);
int		get_positions_start(t_data *data, char **argv);
int		is_texture_3(char *s);
int		is_color_2(char *s);
int		file_in_order(char *s);
char	**tab_in_order(t_data *data);
char	**color_in_order(t_data *data);
void	len_max_map(t_data *data, char **argv);
int		good_letters(t_data *data, char **tab);
int		is_valid_map(t_data *data);
void	init_mlx(t_data *data);
int		print_error(char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		check_player(char **map, int i, int j);
void	ft_bzero(void *s, size_t n);

#endif