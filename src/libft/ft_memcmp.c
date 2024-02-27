/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:38:29 by npatron           #+#    #+#             */
/*   Updated: 2023/03/29 18:51:31 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

/*int main(void)
{
	printf("%d\n\n", memcmp("bonjour", "bonjous", 15));
	printf("%d\n\n", ft_memcmp("bonjour", "bonjous", 15));
	return (0);
}*/