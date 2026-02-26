/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:56:49 by beldemir          #+#    #+#             */
/*   Updated: 2026/02/26 17:57:07 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini.h"

static void	move_light(int key)
{
	t_mini	*m;

	m = mini();
	if (key == XK_W || key == XK_w)
		m->l.coords.z += MOVE_SPEED;
	if (key == XK_A || key == XK_a)
		m->l.coords.x -= MOVE_SPEED;
	if (key == XK_S || key == XK_s)
		m->l.coords.z -= MOVE_SPEED;
	if (key == XK_D || key == XK_d)
		m->l.coords.x += MOVE_SPEED;
	if (key == XK_space)
		m->l.coords.y += MOVE_SPEED;
	else if (key == XK_Shift_L || key == XK_Shift_R)
		m->l.coords.y -= MOVE_SPEED;
}

int	light_moves(int key)
{
	if (key == XK_W || key == XK_w
		|| key == XK_A || key == XK_a
		|| key == XK_S || key == XK_s
		|| key == XK_D || key == XK_d
		|| key == XK_Shift_L || key == XK_Shift_R
		|| key == XK_space)
		move_light(key);
	else
		return (FAIL);
	return (SUCCESS);
}
