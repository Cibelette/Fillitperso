/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagier <clagier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:32:06 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/17 16:29:20 by clagier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int    is_file_ok(int fd)
{
    char *line;
    int     i;
    int        j;
    int ret;

	ret = 1;
    while (ret == 1)
	{
		while (j < 4)
		{
			i = 0;
			ret = get_next_line(fd, &line);
			while (line[i] == '.' || line[i] == '#')
				i++;
			if (line[i] != '\0' || i != 4)
				return (1);
			j++;
		}
		ret = get_next_line(fd, &line);
		if (line[0] != '\n' || line[1] != '\0')
			return (1);
	}

}

int        ft_fillit(int fd)
{
    if (fd < 0)
        return (1);

    if (is_file_ok(fd) == 1)
        return (1);
    return (0);
}
