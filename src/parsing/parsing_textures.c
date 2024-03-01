/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:01:32 by npatron           #+#    #+#             */
/*   Updated: 2024/02/29 19:43:37 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


int is_texture(t_data *data, char *s)
{
    int i;

    i = 0;
    while(s[i] == ' ')
        i++;
    if (s[i] == 'N' && (s[i + 1] == ' ' || s[i + 1] == 'O'))
    {
        data->no++;
        return (1);
    }
    else if (s[i] == 'S' && (s[i + 1] == ' ' || s[i + 1] == 'O'))
    {
        data->so++;
        return (1);
    }
    else if (s[i] == 'W' && (s[i + 1] == ' ' || s[i + 1] == 'E'))
    {
        data->we++;
        return (1);
    }
    else if (s[i] == 'E' && (s[i + 1] == ' ' || s[i + 1] == 'A'))
    {
        data->ea++;
        return (1);
    }
    else
        return (0);
}

int condition_texture(t_data *data)
{
    if (data->ea == 1 && data->no == 1
        && data->we == 1 && data->so == 1)
        return (0);
    return (1);
}

int in_order(t_data *data)
{
    int count;
    int i;
    int j;
    
    count = 0;
    i = 0;
    while (data->textures[i])
    {
        j = 0;
        while (data->textures[i][j] == ' ')
            j++;
        if (i == 0 && data->textures[i][j] == 'N')
            count++;
        else if (i == 1 && data->textures[i][j] == 'S')
            count++;
        else if (i == 2 && data->textures[i][j] == 'W')
            count++;
        else if (i == 3 && data->textures[i][j] == 'E')
            count++;
        i++;
    }
    if (count != 4)
        return (1);
    return (0);
}

int    get_textures(t_data *data, char **argv)
{
    int     i;
    char    *s;
    int     fd;

    i = 0;
    fd = open(argv[1], O_RDONLY);
    data->textures = malloc(sizeof(char *) * (4 + 1));
    s = get_next_line(fd);
    while (s)
    {
        if (jump_line(s) == 0 && is_texture(data, s) == 1)
        {
            data->textures[i] = s;
            i++;
        }
        s = get_next_line(fd);
        if (i == 4)
            break;
    }
    data->textures[i] = NULL;
    if (condition_texture(data) == 1 || in_order(data) == 1)
		return (1);
    return (0);
}




