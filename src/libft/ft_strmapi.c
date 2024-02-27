/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:24:39 by npatron           #+#    #+#             */
/*   Updated: 2023/04/11 14:45:42 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_lenmapi(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	i;
	unsigned int	j;

	dest = malloc(sizeof(char) * (ft_lenmapi(s) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		dest[j] = f(i, s[i]);
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
