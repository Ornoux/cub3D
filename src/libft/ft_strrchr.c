/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:40:13 by npatron           #+#    #+#             */
/*   Updated: 2023/04/12 15:39:39 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
		i++;
	while (i > 0)
	{
		if (s[i] == ((char)c))
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == ((char)c))
		return ((char *)&s[i]);
	return (NULL);
}
