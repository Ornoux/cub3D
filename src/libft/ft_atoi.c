/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:03:03 by npatron           #+#    #+#             */
/*   Updated: 2023/04/11 14:34:34 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == ' ' || c == '\f' || \
		c == '\v' || c == '\r')
	{
		return (1);
	}
	return (0);
}

static int	numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	output;

	i = 0;
	minus = 0;
	output = 0;
	while (is_space(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	while (numeric(str[i]) == 1)
	{
		output = (output * 10) + (str[i] - '0');
		i++;
	}
	if (minus % 2 == 1)
		return (output *= -1);
	return (output);
}
