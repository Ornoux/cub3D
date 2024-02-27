/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:56:47 by npatron           #+#    #+#             */
/*   Updated: 2023/04/11 14:35:15 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	lenitoa(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	s = malloc(sizeof (char) * (lenitoa(n) + 1));
	if (!s)
		return (NULL);
	i = lenitoa(n);
	if (n < 0)
	{
		s[0] = '-';
		n = -1 * n;
	}
	s[i] = '\0';
	while (n > 0)
	{
		s[i - 1] = '0' + (n % 10);
		n = (n / 10);
		i--;
	}
	return (s);
}
/*
int main()
{
	printf("%s", ft_itoa(26569));
	return 0;
}
*/