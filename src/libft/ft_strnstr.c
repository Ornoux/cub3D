/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:56:58 by npatron           #+#    #+#             */
/*   Updated: 2023/04/11 14:43:19 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!*needle)
		return ((char *)&haystack[0]);
	if (n == 0)
		return (NULL);
	i = 0;
	while ((i < n) && haystack[i])
	{
		j = i;
		k = 0;
		while ((haystack[j] == needle[k]) && (j < n))
		{
			j++;
			k++;
			if (!needle[k])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	printf("%s\n", ft_strnstr("Bonjour", "j", 4));
	printf("%s", strnstr("Bonjour", "j", 4));
	return 0;
}*/