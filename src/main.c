/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:20:44 by npatron           #+#    #+#             */
/*   Updated: 2024/02/27 20:28:53 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	int	fd;

	(void)argc;
	(void)argv;
	fd = open("texte.ber", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}
