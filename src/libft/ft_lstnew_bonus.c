/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:04:00 by npatron           #+#    #+#             */
/*   Updated: 2023/04/16 13:27:49 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*rtr;

	rtr = (t_list *)malloc(sizeof(*rtr));
	if (!rtr)
		return (NULL);
	rtr -> content = content;
	rtr -> next = NULL;
	return (rtr);
}
