/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:56:15 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/16 04:37:04 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			check_rotation_angles(t_view *view)
{
	if (view->x_rot < 0.0f)
		view->x_rot = 6.3000006f;
	if (view->x_rot > 6.3000006f)
		view->x_rot = 0.0f;
	if (view->y_rot < 0.0f)
		view->y_rot = 6.3000006f;
	if (view->y_rot > 6.3000006f)
		view->y_rot = 0.0f;
	if (view->z_rot < 0.0f)
		view->z_rot = 6.3000006f;
	if (view->z_rot > 6.3000006f)
		view->z_rot = 0.0f;
}

int				expose(t_view *view)
{
	view->x_rot = 0.0f;
	view->y_rot = 0.0f;
	view->z_rot = 0.0f;
	view->perspective = 0;
	reset_view(view);
	refresh_render(view);
	return (0);
}

void			reset_view(t_view *view)
{
	set_scale(view);
	view->x_rot = 0.0f;
	view->y_rot = 0.0f;
	view->z_rot = 0.0f;
}

int				key_events(int keycode, t_view *v)
{
	if (EXIT(keycode))
	{
		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	check_rotation_angles(v);
	if (POS_XROT(keycode) || NEG_XROT(keycode))
		v->x_rot += (POS_XROT(keycode)) ? 0.05f : -0.05f;
	if (POS_YROT(keycode) || NEG_YROT(keycode))
		v->y_rot += (POS_YROT(keycode)) ? 0.05f : -0.05f;
	if (POS_ZROT(keycode) || NEG_ZROT(keycode))
		v->z_rot += (POS_ZROT(keycode)) ? 0.05f : -0.05f;
	if (ZOOM_IN(keycode) || ZOOM_OUT(keycode))
		v->scale -= (ZOOM_OUT(keycode) && v->scale > 2.0) ? 1.0f : -1.0f;
	if (TRANS_LEFT(keycode) || TRANS_RIGHT(keycode))
		v->x_offset += (TRANS_LEFT(keycode)) ? -10.0f : 10.0f;
	if (TRANS_UP(keycode) || TRANS_DOWN(keycode))
		v->y_offset += (TRANS_UP(keycode)) ? -10.0f : 10.0f;
	if (PROJECTION(keycode))
		v->perspective = (v->perspective) ? 0 : 0;
	if (RESET(keycode))
		reset_view(v);
	refresh_render(v);
	return (0);
}
