/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:27:03 by npatron           #+#    #+#             */
/*   Updated: 2024/03/20 18:01:30 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	there_is_point(char *s)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	while (s[i])
	{
		if (s[i] == '.')
			point++;
		i++;
	}
	if (point != 1)
		return (1);
	return (0);
}

int	extension(char *s)
{
	int	i;

	i = 0;
	if (there_is_point(s) == 1)
		return (1);
	while (s[i] != '.')
		i++;
	if (s[i + 1] == 'c' && s[i + 2] == 'u'
		&& s[i + 3] == 'b' && s[i + 4] == '\0')
		return (0);
	else
		return (1);
}

int	good_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Missing one argument to run our program.\n");
		return (1);
	}
	else if (extension(argv[1]) == 1)
	{
		printf("Bad extension. Please...\n");
		return (1);
	}
	else
		return (0);
}
