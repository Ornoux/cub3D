/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:37:38 by npatron           #+#    #+#             */
/*   Updated: 2024/03/07 17:12:03 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	get_positions_end(t_data *data, int fd, char *s)
{
	data->end = data->start - 1;
	while (s)
	{
		if (jump_line(s) == 1)
			break ;
		s = get_next_line(fd);
		data->end++;
	}
	while (s)
	{
		if (jump_line(s) == 0)
		{
			close(fd);
			return (1);
		}
		s = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	get_positions_start(t_data *data, char **argv)
{
	int		count;
	int		fd;
	char	*s;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	s = get_next_line(fd);
	data->start = 1;
	if (!s)
		return (1);
	while (s)
	{
		if (is_texture_3(s) >= 1 || is_color_2(s) >= 1)
			count++;
		s = get_next_line(fd);
		data->start++;
		if (count == 6)
			break ;
	}
	while (s)
	{
		if (jump_line(s) == 0)
			break ;
		s = get_next_line(fd);
		data->start++;
	}
	return (get_positions_end(data, fd, s));
}

void	len_max_map(t_data *data, char **argv)
{
	int		len;
	int		fd;
	char	*s;
	int		i;

	len = 0;
	fd = open(argv[1], O_RDONLY);
	s = get_next_line(fd);
	i = 0;
	while (i <= data->start)
	{
		s = get_next_line(fd);
		i++;
	}
	if (!s)
		return ;
	while (i != data->end)
	{
		if (len < ft_strlen(s))
			len = ft_strlen(s);
		s = get_next_line(fd);
		i++;
	}
	data->len_max = len;
}

void	get_map(t_data *data, char **argv)
{
	int		fd;
	int		i;
	char	*s;

	fd = open(argv[1], O_RDONLY);
	data->map = ft_calloc(sizeof(char *), ((data->end - data->start) + 3));
	s = get_next_line(fd);
	i = 0;
	while (i != data->start - 1)
	{
		s = get_next_line(fd);
		i++;
	}
	i = 1;
	data->map[0] = line(data->len_max);
	while (data->start <= data->end)
	{
		data->map[i] = copy_string(s, data->len_max);
		s = get_next_line(fd);	
		i++;
		data->start++;
	}
	data->map[i] = line(data->len_max);
	i++;
	data->map[i] = '\0';
}
int	good_letters(t_data *data, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (is_good_char(data, tab[i][j], i, j))
				return (1);
			j++;
		}
		i++;
	}
	if (data->player == 0 || data->player > 1)
		return (1);
	return (0);
}

int	is_valid_map(t_data *data)
{
	int	i;
	int	j;
	
	i = 1;
	if (good_letters(data, data->map))
		return (1);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if ((data->map[i][j] == '0' && data->map[i + 1][j] == ' ')
			|| (data->map[i][j] == '0' && data->map[i - 1][j] == ' ')
			|| (data->map[i][j] == '0' && data->map[i][j + 1] == ' ')
			|| (data->map[i][j] == '0' && data->map[i][j - 1] == ' '))
				return (1);
			j++;
		}
		i++;		
	}
	return (0);
}
