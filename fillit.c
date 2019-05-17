/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cibyl <cibyl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:32:06 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/17 22:19:11 by cibyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

typedef struct		s_list
{
	size_t				length;
	struct	s_tetris	*head;
	struct	s_tetris	*tail;
}					t_list;

typedef struct		s_tetris
{
	char			**lines;
	char			*temp;
	struct s_tetris	*next;
	struct s_tetris *prev;
}					t_tetris;

t_list *list_new(void)
{
    t_list *newlist = malloc(sizeof *newlist);
    if (newlist != NULL)
    {
        newlist->length = 0;
        newlist->head = NULL;
        newlist->tail = NULL;
    }
    return (newlist);
}

t_list dlist_append(t_list list, char **lines)
{
    if (list != NULL) 
    {
        t_tetris *newtetri = malloc(sizeof *newtetri); 
        if (newtetri != NULL)
        {
            newtetri->lines = lines; 
            newtetri->next = NULL; 
            if (list->tail == NULL) 
            {
                newtetri->prev = NULL; 
                list->head = newtetri; 
                list->tail = newtetri; 
            }
            else 
            {
                list->tail->next = newtetri; 
                newtetri->prev = list->tail; 
                list->tail = newtetri; 
            list->length++; 
    		}
    	}
    	return (list); 
	}
	return (0);
}

void ft_printline(char line[4][4])
{
	int i;
	
	i = 0;
	while (i < 4)
	{
		ft_putstr(line[i]);
		ft_putchar('\n');
		i++;
	}	
}

int    is_file_ok(int fd)
{
    char **line;
    int     i;
    int		j;
    int ret;
	t_list	list;

	list = list_new();
    ret = 1;
	j = 0;
    while (ret == 1)
    {
        while (j < 4 && ret > 0)
        {
            i = 0;
            ret = get_next_line(fd, &line);
            while (line[j][i] == '.' || line[j][i] == '#')
                i++;
            if (line[i] != '\0' || i != 4)
                return (1);
            j++;
        }
		ft_printline(line);
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