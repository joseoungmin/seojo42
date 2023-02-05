/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:29:14 by seojo             #+#    #+#             */
/*   Updated: 2023/02/06 00:17:23 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_player.h"

void	set_player_dir_sub(t_map *map)
{
	if (map->direction == 'W')
	{
		map->player->dir_x = -1;
		map->player->dir_y = 0;
		map->player->plane_x = 0;
		map->player->plane_y = -0.66;
	}
	else if (map->direction == 'E')
	{
		map->player->dir_x = 1;
		map->player->dir_y = 0;
		map->player->plane_x = 0;
		map->player->plane_y = 0.66;
	}
}

void	set_player_dir(t_map *map)
{
	if (map->direction == 'N')
	{
		map->player->dir_x = 0;
		map->player->dir_y = -1;
		map->player->plane_x = 0.66;
		map->player->plane_y = 0;
	}
	else if (map->direction == 'S')
	{
		map->player->dir_x = 0;
		map->player->dir_y = 1;
		map->player->plane_x = -0.66;
		map->player->plane_y = 0;
	}
	set_player_dir_sub(map);
}
int	draw_player(t_map *map)
{
	const int	p_x = (int)(MINI_SCALE * TILE_SIZE * map->player->x);
	const int	p_y = (int)(MINI_SCALE * TILE_SIZE * map->player->y);
	int			row;
	int			col;

	row = -map->player->thickness;
	while (row <= map->player->thickness)
	{
		col = -map->player->thickness;
		while (col <= map->player->thickness)
		{
			map->world->data[(WINDOW_WIDTH * (p_y + row) + (p_x + col))] = 0x0000FF;
			col++;
		}
		row++;
	}
	return (0);
}
/*
int	draw_player(t_map *map)
{
	const int	p_x = (int)(MINI_SCALE * TILE_SIZE * map->player->x);
	const int	p_y = (int)(MINI_SCALE * TILE_SIZE * map->player->y);
	int			row;
	int			col;

	row = -TILE_SIZE * MINI_SCALE * 3 / 4;
	while (row <= -(TILE_SIZE * MINI_SCALE / 4))
	{
		col = -TILE_SIZE * MINI_SCALE * 3 / 4;
		while (col <= -(TILE_SIZE * MINI_SCALE / 4))
		{
			map->world->data[WINDOW_WIDTH * (p_y + row) + (p_x + col)] = 0x0000FF;
			col++;
		}
		row++;
	}
	return (0);
}*/

void	set_player(t_map *map)
{
	set_player_dir(map);
}
