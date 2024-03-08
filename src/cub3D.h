/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:27:59 by npatron           #+#    #+#             */
/*   Updated: 2024/03/07 17:17:07 by npatron          ###   ########.fr       */
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

typedef struct s_data
{
	int		no;
	int		so;
	int		we;
	int		ea;
	int		sky;
	int		bg;
	int		start;
	int		end;
	char	**map;
	char	**textures;
	char	**colors;
	int		len_max;
	int		tall_map;
	int		*c_floor;
	int		*c_sky;
	int		player;
	int		pos_x;
	int		pos_y;
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
int		first_line_map(char *s);
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



// PARSING PART
int		good_arg(int argc, char **argv);
int		get_textures(t_data *data, char **argv);
int		get_colors(t_data *data, char **argv);
int		condition_texture(t_data *data);
int		condition_color(t_data *data);
int		error_file(t_data *data, char **argv);
void	clean_tab(t_data *data);
int		is_texture(t_data *data, char *s);
void	find_map(t_data *data, char **argv);
int		check_colors(int *tab);
int		split_colors(t_data *data);
void	find_max_len(t_data *data, char **argv);
void	find_end_map(t_data *data, char **argv);
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
int		texture_is_xpm(char *str);



#endif