/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:13:27 by nicolas           #+#    #+#             */
/*   Updated: 2023/04/16 13:30:40 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s || start >= 4294967295 || ft_strlen(s) < start)
	{
		dest = malloc(sizeof(char *) * 1);
		dest[0] = '\0';
		return (dest);
	}
	dest = (char *)malloc(ft_strlen(s) - start + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			dest[j++] = s[i];
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
/*
int main()
{
    printf("%s", ft_substr("", 0, 3));
    return (0);
}*/