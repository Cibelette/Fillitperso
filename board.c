/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cibyl <cibyl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:47:54 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/03 13:45:31 by cibyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_map(char **map, int map_size)
{
	int		i;

	i = 0;
	while (i < map_size + 4)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map[i]);
	map[i] = NULL;
	free(map);
	map = NULL;
}

void	print_map(char **map, int map_size)
{
	int i;
	int j;

	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (j < map_size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

t_map	*extend_tab(t_map *map, size_t new_size)
{
	size_t		i;

	if (!(map->tab = (char **)malloc(sizeof(char *) * new_size)))
		return (NULL);
	i = 0;
	while (i < new_size)
	{
		map->tab[i] = ft_strnew_with_dot(new_size);
		i++;
	}
	ft_putstr("le putst\n");
	ft_putstr(map->tab[0]);
	ft_putchar('\n');
	ft_putchar(map->tab[0][1]);
	//printf("\n le printf\n %s et 00 = %c", newtab[0], newtab[0][0]);
	map->tab[i] = 0;
	return (map);
}

t_map	*init_map(t_map *map)
{
	int		x;
	int		y;
    size_t  size;

    size = 2;
    if (map)
    {
        size = map->size + 1;
        free(map);
    }
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->x = 0;
	map->y = 0;	
	map->size = size;
	map = extend_tab(map, map->size);
	printf("\n***\n");
	ft_putstr(map->tab[0]);
	printf("\n***\n");
	//printf("%zu\n%zu\n", list->tetri, map->size);
	return (map);
}
