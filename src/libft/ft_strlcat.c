/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:30:13 by npatron           #+#    #+#             */
/*   Updated: 2023/04/11 14:45:33 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	destsize;
	size_t	srcsize;

	destsize = ft_strlen(dest);
	srcsize = 0;
	while (src[srcsize])
		srcsize++;
	j = destsize;
	i = 0;
	if (destsize < n && n > 0)
	{
		while (src[i] != '\0' && destsize + i < n - 1)
		{
			dest[j] = src[i];
			i++;
			j++;
		}
		dest[j] = '\0';
	}
	if (destsize >= n)
		destsize = n;
	return (destsize + srcsize);
}
