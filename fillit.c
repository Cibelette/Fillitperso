/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cibyl <cibyl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:32:06 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/17 21:44:16 by cibyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

typedef struct		s_list
{
	size_t				lenght;
	struct	t_tetris	*head;
	struct	t_tetris	*tail;
}					t_list;

typedef struct		s_tetris
{
	char			lines[4][4];
	char			*temp;
	struct s_gnl	*next;
}					t_tetris;

t_list *list_new(void)
{
    Dlist *newlist = malloc(sizeof *newlist);
    if (newlist != NULL)
    {
        newlist->length = 0;
        newlist->p_head = NULL;
        newlist->p_tail = NULL;
    }
    return newlist;
}

int    is_file_ok(int fd)
{
    char *line;
    int     i;
    int		j;
    int ret;

    ret = 1;
	j = 0;
    while (ret == 1)
    {
        while (j < 4 && ret > 0)
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
		if (ret == 0)
			return (0);
        if (line[0] != '\0')
            return (1);
        j = 0;
    }
    return (0);
}

int        ft_fillit(int fd)
{
    int ok;

    if (fd < 0)
        return (1);

    ok = is_file_ok(fd);

    return (ok);
}