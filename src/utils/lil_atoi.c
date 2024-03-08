/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:52:28 by npatron           #+#    #+#             */
/*   Updated: 2024/03/05 18:11:56 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	lil_atoi(char *s)
{
	int			i;
	long long	res;
	int			len;

	i = 0;
	res = 0;
	len = 0;
	while (s[i] != '\n' && s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		res = res * 10 + (s[i] - '0');
		i++;
		len++;
	}
	if (len > 10 || res > INT_MAX)
		return (5);
	return (res);
}
