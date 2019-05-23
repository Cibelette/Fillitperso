/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagier <clagier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:25:31 by clagier           #+#    #+#             */
/*   Updated: 2019/05/23 14:12:47 by clagier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map init_map(void)
{
	t_map *map;
	int		x;
	int		y;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->x = 0;
	map->size = 2;

	(while map->x < map->size)
	{
		map->y = 0;
		while (map->y < (map->size))
		{
			map->map[map->x][map->y] = '.';
			map->y++;
		}
		map->map[map->x][map->y] = '\0';
		map->x++;		
	}
	map->x = 0;
	map->y = 0;

	return (map);
}
int place_block(t_tetris *current, int i, int j, t_map map)
{
	while(map->map[map->x])
	{
		while (map->map[map->x][map->y])
			while (map->map[map->x][map->y] != '.')
				map->y++;
			
		
	}
}


int find_block_long(t_tetris *current, int i, int j)
{
	while (current->lines[i])
	{
		while (current->lines[i][j])
		{
			while (current->lines[i][j] == '.')
				j++;
			if (current->lines[i][j] > 'A' && current->lines[i][j] < 'Z')
				return (i);
		}
		j = 0;
		i++;
	}
	return (-1);
}

int find_block_lat(t_tetris *current, int i, int j)
{
	while (current->lines[i])
	{
		while (current->lines[i][j])
		{
			while (current->lines[i][j] == '.')
				j++;
			if (current->lines[i][j] > 'A' && current->lines[i][j] < 'Z')
				return (j);
		}
		j = 0;
		i++;
	}
	return (-1);
}