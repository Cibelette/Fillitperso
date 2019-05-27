/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagier <clagier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:25:31 by clagier           #+#    #+#             */
/*   Updated: 2019/05/27 14:47:31 by clagier          ###   ########.fr       */
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

int place_next_block(t_tetris *current, int i, int j, t_map map, char letter)
{
	int block;
	int inext;
	int jnext;
	char **tmp;

	tmp = map->map;
	block = 0;

	while(block < 3)
	{
		inext = find_block_lat(current, i, j);
		jnext = find_block_long(current, i, j);
		map->x += (inext - i);
		map->y += (jnext - j)
		if (map->x < 0 || map->y < 0 || tmp[map->x][map->y] != '.')
			return (-1);
		tmp[map->x][map->y] = letter;
		i = inext;
		j = jnext;
		block++;
	}
	map->map = tmp;
	free(tmp)
	map->x = 0;
	map->y = 0;
}

int		place_block(t_tetris *current, t_map *map, char letter, int x, int y)
{
	int i;
	int j;
	int ok;
	
	i = find_block_lat(current, 0, 0);
	j = find_block_long(current,0 , 0);

	while (map->map[x])
	{
		while (map->map[x][y])
		{
			while (map->map[x][y] != '.')
				map->y++;
			if (map->map[x][y] == '.')
			{
				map->x = x;
				map->y = y;
				ok = place_next_block(current, i, j, map, letter);
				if ( ok == 0)
				{
					map->map[x][y] = letter;
					if (current = current->next == NULL)
						return (0);
					return(1);

				}
				else if (ok = -1)
					place_blocks(current, map, letter, x, y + 1)

			}
		}
		y = 0;
		x++;
	}
	return (-1);
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
				return (j);
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
				return (i);
		}
		j = 0;
		i++;
	}
	return (-1);
}

int		solve_map(t_map map)
{
	t_tetris	*current;
	char		letter;
	int i;

	current = list->first;
	letter = 'A';
	i = 1;
	while (i == 1)
	{
		i = place_block(current, map, letter, 0, 0);
		current = current->next;
		letter++;
	}
	if (i = -1)
	{
		free_map(map->map, map->size);
		init_map(map);
		solve_map(map);
	}

}