/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:21:34 by seojo             #+#    #+#             */
/*   Updated: 2023/01/26 10:54:57 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

typedef struct s_world	t_world;

struct s_world
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*data;
	int		bpp;
	int		line_len;
	int		endian;
};

#endif