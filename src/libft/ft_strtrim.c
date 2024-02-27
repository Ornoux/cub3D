/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:59:49 by nicolas           #+#    #+#             */
/*   Updated: 2023/04/16 13:29:36 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	compte(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*mempb(char *dupli)
{
	dupli = malloc(1 * sizeof(char));
	dupli[0] = '\0';
	return (dupli);
}

int	char_is_trimm(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	int		i;
	int		end;
	int		start;
	char	*dest;

	i = 0;
	end = compte(s);
	start = 0;
	dest = 0;
	if (s == set || (!*s && set))
		return (mempb(dest));
	while (char_is_trimm(s[i], set) && s[i])
		i++;
	while (char_is_trimm(s[end - 1], set) && end > i)
		end--;
	dest = (char *)malloc(sizeof(*s) * (end - i + 1));
	if (!dest || !s)
		return (NULL);
	while (i < end)
		dest[start++] = s[i++];
	dest[start] = 0;
	return (dest);
}
/*
int main()
{
    printf("%s\n", ft_strtrim("", ""));
    return (0);
}*/