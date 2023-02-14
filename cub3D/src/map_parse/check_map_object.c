/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:40:52 by seojo             #+#    #+#             */
/*   Updated: 2023/02/13 03:41:32 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "check_map_object.h"

char	*pass_newline(int fd, char *read_line, int *file_height)
{
	while (read_line != NULL && *read_line == '\n')
	{
		safe_free(read_line);
		read_line = get_next_line(fd);
		(*file_height)++;
	}
	return (read_line);
}

int	check_tex_and_col(t_world *world)
{
	if (world->tex_path[NO] == NULL || world->tex_path[SO] == NULL \
	|| world->tex_path[WE] == NULL || world->tex_path[EA] == NULL \
	|| world->floor == -1 || world->ceiling == -1)
		return (1);
	return (0);
}

char	*compare_arguments(t_world *world, int fd, \
char *read_line, int *file_height)
{
	while (read_line != NULL && check_tex_and_col(world))
	{
		read_line = pass_newline(fd, read_line, file_height);
		if (ft_strncmp("NO ", read_line, 3) == 0)
			world->tex_path[NO] = check_path(read_line + 2);
		else if (ft_strncmp("SO ", read_line, 3) == 0)
			world->tex_path[SO] = check_path(read_line + 2);
		else if (ft_strncmp("WE ", read_line, 3) == 0)
			world->tex_path[WE] = check_path(read_line + 2);
		else if (ft_strncmp("EA ", read_line, 3) == 0)
			world->tex_path[EA] = check_path(read_line + 2);
		else if (ft_strncmp("F ", read_line, 2) == 0)
			world->floor = check_color(read_line + 1);
		else if (ft_strncmp("C ", read_line, 2) == 0)
			world->ceiling = check_color(read_line + 1);
		else
			err_exit("Insufficient contents");
		safe_free(read_line);
		read_line = get_next_line(fd);
		(*file_height)++;
	}
	return (read_line);
}

int	check_component(t_world *world, int fd)
{
	char	*read_line;
	int		file_height;

	file_height = 0;
	read_line = get_next_line(fd);
	read_line = compare_arguments(world, fd, read_line, &file_height);
	read_line = pass_newline(fd, read_line, &file_height);
	safe_free(read_line);
	return (file_height);
}
