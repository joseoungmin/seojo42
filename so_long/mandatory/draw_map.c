/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:21:15 by seojo             #+#    #+#             */
/*   Updated: 2022/10/07 02:33:42 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	open_map(char *map)
{
	int fd;

	fd = open(map, O_RDONLY);
	if (fd <= 0)
		ft_error("open error");
	return (fd);
}

int	map_obj_check(char c, int *objs)
{
	if (c == '1' || c == '0')
		continue ;
	else if (c == 'C')
		objs[COIN]++;
	else if (c == 'E')
		objs[EXIT]++;
	else if (c == 'P')
		objs[P]++;
	else
		return (1);
	return (0);
}

void	map_size_objs_ck(t_game *game, int fd)
{
	int		i;
	char	c;
	int		objs[3];

	objs[P] = 0;
	objs[COIN] = 0;
	objs[EXIT] = 0; 
	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (map_obj_check(c, objs))
			ft_error("objs error");
		if (game->map_cols < i)
			game->map_cols = i;
		if (c == '\n')
		{
			game->map_rows++;
			i = 0;
		}
		else
			i++;
	}
	if (objs[P] != 1 || objs[COIN] < 1 || objs[EXIT] < 1)
		ft_error("object count error");
}

void	map_malloc(t_game *game, int fd)
{
	int	i;

	map_size_objs_ck(game, fd);
	game->map_arr = (char **)malloc(sizeof(char *) * game->map_rows);
	if (!game->map_arr)
		ft_error("malloc error");
	i = -1;
	while (++i != game->map_cols)
	{
		game->map_arr[i] = (char *)malloc(sizeof(char *) * game->map_cols);
		if (!game->map_arr[i])
			ft_error("malloc error");
	}
}

void	map_load(char *map, t_game *game, int fd)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	fd = open_map(map);
	line = get_next_line(fd);
	game->map_wid = ft_strlen(line);        // -1;
	i = 0;
	while (line)
	{
		game->map_hei++;
		if (game_wid != ft_strlen(line))    // -1;
			ft_error("map width error");
		j = 0;
		while (j < game->map_cols)
		{
			game->map_arr[i][j] = line[j];
			j++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	map_wall_ck(t_game *game)
{
	int	i;
	
	i = 0;
	while (game->map_arr[0][i])
		if (game->map->arr[0][i++] != '1')
			ft_error("wall error");
	i = 0;
	while (game->map_arr[i][0])
		if (game->map->arr[i++][0] != '1')
			ft_error("wall error");
	i = 0;
	while (game->map_arr[i][game->map_cols - 1])
		if (game->map->arr[i++][game->map_cols - 1] != '1')
			ft_error("wall error");
	i = 0;
	while (game->map_arr[game->map_rows - 1][i])
		if (game->map->arr[game->map_rows - 1][i++] != '1')
			ft_error("wall error");
}

void	map_init(char *map, t_game *game)
{
	const int	map_name_len = ft_strlen(map);
	int			fd;

	if (map_name_len < 5 || ft_strncmp(map[map_name_len - 4], ".ber" ,4))
		ft_error(0);
	fd = open_map(map);
	map_malloc(game, fd);
	close(fd);
	map_load(map, game);
	map_wall_ck(game);
}
