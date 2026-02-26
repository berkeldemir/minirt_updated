/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:07:13 by beldemir          #+#    #+#             */
/*   Updated: 2026/02/26 18:10:50 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini.h"

int	destroy_notify(void *null)
{
	(void)null;
	quit(MSG_OK, SUCCESS);
	return (SUCCESS);
}

int	basic_controls(int key)
{
	if (key == XK_Escape || key == XK_Q || key == XK_q)
		quit(MSG_OK, SUCCESS);
	else if (key == XK_R || key == XK_r)
	{
		(ft_lstclear(&mini()->objs, free), parser());
		(render(), put_img_to_win());
	}
	else if ((key == XK_X || key == XK_x) && mini()->shadows == ON)
		mini()->shadows = OFF;
	else if ((key == XK_X || key == XK_x) && mini()->shadows == OFF)
		mini()->shadows = ON;
	else if (key == XK_C || key == XK_c)
		return (state(SET, NULL), TRUE);
	else if (key == XK_L || key == XK_l)
		return (state(SET, (t_obj *)FOCUS_LIGHT), TRUE);
	else
		return (FALSE);
	return (TRUE);
}
