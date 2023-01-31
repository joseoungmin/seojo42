/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eight_direction.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:43:50 by seojo             #+#    #+#             */
/*   Updated: 2023/01/23 23:43:14 by seojo            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_EIGHT_DIRECTION_H
# define CHECK_EIGHT_DIRECTION_H
# include "map.h"
# include "error.h"

void	check_eight_directions(t_map *tmap, char **map, int height, int width);

#endif