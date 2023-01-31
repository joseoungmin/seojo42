/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:57:29 by seojo             #+#    #+#             */
/*   Updated: 2023/01/31 15:24:28 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_map.h"

void	fill_rectangle(t_map *map, int x, int y, int color)
{
	int		i;
	int		j;

	j = 0;
	while (j < (int)(MINI_SCALE * TILE_SIZE))
	{
		i = 0;
		while (i < (int)(MINI_SCALE * TILE_SIZE))
		{
			map->world->data[(int)(MINI_SCALE * map->width * TILE_SIZE) * \
			(y + j) + (x + i)] = color;
			i++;
		}
		j++;
	}
}

void	render_map(t_map *map)
{
	int		col;
	int		row;

	map->world->data = (int *)mlx_get_data_addr(map->world->img, \
			&map->world->bpp, &map->world->line_len, &map->world->endian);
	row = -1;
	while (++row < map->height)
	{
		col = -1;
		while (++col < map->width)
		{
			if (map->map[row][col] == '1')
				fill_rectangle(map, (int)(col * TILE_SIZE * MINI_SCALE), \
						(int)(row * TILE_SIZE * MINI_SCALE), 0x282828);
			else if (map->map[row][col] == '0')
				fill_rectangle(map, (int)(col * TILE_SIZE * MINI_SCALE), \
						(int)(row * TILE_SIZE * MINI_SCALE), 0xFFFFFF);
			else if (map->map[row][col] == ' ')
				fill_rectangle(map, (int)(col * TILE_SIZE * MINI_SCALE), \
						(int)(row * TILE_SIZE * MINI_SCALE), 0x000000);
			else
				fill_rectangle(map, (int)(col * TILE_SIZE * MINI_SCALE), \
						(int)(row * TILE_SIZE * MINI_SCALE), 0xFFFFFF);
		}
	}
}