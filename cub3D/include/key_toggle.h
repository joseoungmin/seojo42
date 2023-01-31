/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_toggle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:25:00 by seojo             #+#    #+#             */
/*   Updated: 2023/01/31 16:30:27 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_TOGGLE_H
# define KEY_TOGGLE_H
# include "map.h"
# include "move.h"
# include <stdlib.h>
# include <math.h>

t_key	*init_key(void);
void	move_check(t_map *map);
int		key_press(int keycode, t_map *map);
int		key_release(int keycode, t_map *map);

#endif